# `condrv_hook_keyinit()`

## 用途
`IOCS _KEY_INIT`をフックする。

## 書式
```c
#include <condrv.h>
int condrv_hook_keyinit(void* addr);
```

## 解説
`condrv_hook_keyinit()`関数は、`IOCS _KEY_INIT`の処理をフックし、
`addr`で指定した関数が呼ばれるように設定する。

condrv(em).sysは`IOCS _KEY_INIT`の処理アドレスを介したAPIを使用しているので、
同コールの処理アドレスを外部のプログラムに設定することができない。
よって、`condrv_hook_keyinit()`関数は実際に`IOCS _KEY_INIT`をフックするのではなく、
condrv(em).sysから呼び出すアドレスを内部ワークに設定している。

## 戻り値
以前に設定されていた`IOCS _KEY_INIT`の処理アドレスを返す。

エラーが発生した場合は負数を返す。

## 注意
`addr`はIOCSコールとして作成された関数(サブルーチン)でなければならない。

## 規格
libcondrv

## 関連項目
[condrv_get_keyinit_adr](get_keyinit_adr.md), [condrv_unhook_keyinit](unhook_keyinit.md)
