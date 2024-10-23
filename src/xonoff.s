.title libcondrv - xonoff.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_getlevel::
  moveq #0,d1
  bra @f
_condrv_xon::
  moveq #-1,d1
  bra @f
_condrv_xoff::
  moveq #+1,d1
@@:
  SUPER_CALL
  GET_WORK
  bne error_return

  SYSCALL COND_LEVEL
  rts
error_return:
  moveq #-1,d0
  rts


.end

* End of File --------------------------------- *
