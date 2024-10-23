.title libcondrv - pushpop.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_push::
  moveq #1,d1
  bra @f
_condrv_pop::
  moveq #0,d1
@@:
  SUPER_CALL
  GET_WORK
  bne error_return

  SYSCALL COND_STACK
  move.l d0,d1
  move.l #$000e_ffff,-(sp)
  DOS _CONCTRL
  addq.l #4,sp
  move.l d1,d0
  rts
error_return:
  moveq #-1,d0
  rts


.end

* End of File --------------------------------- *
