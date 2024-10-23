.title libcondrv - stop_keypast.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_stop_keypaste::
  SUPER_CALL
  GET_WORK
  bne error_return

  lea (nul_string,a0),a1
  movea.l (keybuf_addr,a0),a2
  move.l a1,(paste_ptr,a2)  ;NULのアドレスを設定

  moveq #0,d0
  rts
error_return:
  moveq #-2,d0
  rts


.end

* End of File --------------------------------- *
