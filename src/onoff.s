.title libcondrv - onoff.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_on::
  moveq #1,d1
  bra @f
_condrv_off::
  moveq #0,d1
@@:
  SUPER_CALL
  GET_WORK
  bne skip

  SYSCALL COND_ONOFF
  move.l #$000e_ffff,-(sp)
  DOS _CONCTRL
  addq.l #4,sp
skip:
  rts


.end

* End of File --------------------------------- *
