.title libcondrv - getver.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_getver::
  SUPER_CALL
  GET_WORK
  bne error_return

  SYSCALL COND_GETVER
  rts
error_return:
  moveq #-2,d0
  rts


.end

* End of File --------------------------------- *
