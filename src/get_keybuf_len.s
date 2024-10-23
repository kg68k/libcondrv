.title libcondrv - get_keybuf_len.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_get_keybuf_len::
  SUPER_CALL
  GET_WORK
  bne error_return

  move.l (keybuf_len,a0),d0
  rts
error_return:
  moveq #-1,d0
  rts


.end

* End of File --------------------------------- *
