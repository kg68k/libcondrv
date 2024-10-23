.title libcondrv - write.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_write::
  movem.l (sp),d0/a1-a2
  SUPER_CALL
  GET_WORK
  bne error_return

  move #1,-(sp)  ;write
  pea (xcon,pc)
  DOS _OPEN
  addq.l #6,sp
  move.l d0,d1
  bmi return  ;open error

  move.l a2,-(sp)
  pea (a1)
  move d0,-(sp)
  DOS _WRITE
  move.l d0,d1
  DOS _CLOSE
  addq.l #10-4,sp
  move.l d1,(sp)+
  bmi return  ;write error
  tst.l d0
  bmi close_error
return:
  move.l d1,d0
close_error:
  rts
error_return:
  moveq #-1,d0
  rts


xcon: .dc.b 'XCON',0
.even


.end

* End of File --------------------------------- *
