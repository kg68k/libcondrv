.title libcondrv - keypast.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_keypaste::
  movem.l (sp),d0/a1-a2
  SUPER_CALL
  GET_WORK
  bne error_return

  cmpa.l (keybuf_len,a0),a2
  bcc size_error
  move.l a2,d0  ;len

  movea.l (keybuf_addr,a0),a2
  lea (nul_string,a0),a0
  move.l a0,(paste_ptr,a2)  ;空文字列にしておく
  lea (keybuf_top,a2),a0
  bra @f
  copy_loop:
    move.b (a1)+,(a0)+  ;バッファに転送
  @@:
  dbra d0,copy_loop
  clr d0
  subq.l #1,d0
  bcc copy_loop

  clr.b (a0)
  move.l a2,(paste_ptr,a2)  ;ペーストポインタを設定
  moveq #0,d0
  rts
error_return:
  moveq #-2,d0
  rts
size_error:
  moveq #-1,d0
  rts


.end

* End of File --------------------------------- *
