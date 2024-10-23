.title libcondrv - hook.s


* Include File -------------------------------- *

.include libcondrv.mac


* Text Section -------------------------------- *

.cpu 68000

.text
.even

_condrv_get_keyinit_adr::
  moveq #COND_LAST,d1
  bra @f
_condrv_hook_keyinit::
  movea.l (4,sp),a1
  moveq #COND_HOOK,d1
  bra @f
_condrv_unhook_keyinit::
  movem.l (sp),d0/a1-a2
  moveq #COND_UNHOOK,d1
@@:
  SUPER_CALL
  GET_WORK
  bne error_return

  movea.l (syscall_adr,a0),a0
  jmp (a0)
  ;rts
error_return:
  moveq #-1,d0
  rts


.end

* End of File --------------------------------- *
