// condrv.h - libcondrv header file
// Copyright (C) 2024 TcbnErik

// Copying and distribution of this file, with or without modification,
// are permitted in any medium without royalty provided the copyright
// notice and this notice are preserved.  This file is offered as-is,
// without any warranty.

#ifndef condrv_h
#define condrv_h

#ifdef __cplusplus
extern "C" {
#endif

int condrv_getver(void);
int condrv_getlevel(void);
int condrv_xon(void);
int condrv_xoff(void);
int condrv_get_keymode(void);
int condrv_kon(void);
int condrv_koff(void);
int condrv_write(const char* buf, int size);
int condrv_get_keybuf_len(void);
int condrv_keypaste(const char* buf, int size);
int condrv_keypaste_once(const char* buf);
int condrv_stop_keypaste(void);
void* condrv_get_keyinit_adr(void);
void* condrv_hook_keyinit(void* addr);
int condrv_unhook_keyinit(void* now_addr, void* orig_addr);

#ifdef __cplusplus
}
#endif

#endif
