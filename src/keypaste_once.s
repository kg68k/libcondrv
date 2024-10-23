.title libcondrv - keypaste_once.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_keypaste_once::
  movea.l (4,sp),a1
  SUPER_CALL
  GET_WORK
  bne error_return

  movea.l (keybuf_addr,a0),a2
  move.l a1,(paste_ptr,a2)  ;ペーストポインタを設定
  moveq #0,d0
  rts
error_return:
  moveq #-2,d0
  rts


.end

* End of File --------------------------------- *
