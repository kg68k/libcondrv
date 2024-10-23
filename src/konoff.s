.title libcondrv - konoff.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_kon::
  moveq #0,d1
  bra @f
_condrv_koff::
  moveq #-1,d1
  bra @f
_condrv_get_keymode::
  moveq #1,d1
@@:
  SUPER_CALL
  GET_WORK
  bne error_return

  moveq #0,d0
  move.b (winkey_flag,a0),d0
  tst.b d1
  bgt @f  ;get_keymode
    move.b d1,(winkey_flag,a0)  ;kon or koff
  @@:
  rts
error_return:
  moveq #-1,d0
  rts


.end

* End of File --------------------------------- *
