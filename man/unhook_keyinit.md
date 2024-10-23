# `condrv_unhook_keyinit()`

## 用途
`IOCS _KEY_INIT`のフックを解除する。

## 書式
```c
#include <condrv.h>
int condrv_unhook_keyinit(void* now_addr, void* orig_addr);
```

## 解説
`condrv_unhook_keyinit()`関数は、`condrv_hook_keyinit()`関数でフックした`IOCS _KEY_INIT`を元に戻す。
`now_addr`には現在設定されているはずの処理アドレスを指定する。condrv(em).sysの内部ワークに
保持されている処理アドレスがこの値と違う場合、フックの解除はできずエラーになる。
`orig_addr`は変更する前の処理アドレスを指定する。

## 戻り値
以前に設定されていた`IOCS _KEY_INIT`の処理アドレスを返す。

エラーが発生した場合は負数を返す。

## 注意
`orig_addr`は`condrv_hook_keyinit()`の返値を指定する。

処理アドレスが変更されていた場合はエラーとなる。

## 規格
libcondrv

## 関連項目
[condrv_get_keyinit_adr()](get_keyinit_adr.md), [condrv_hook_keyinit()](hook_keyinit.md)
