# `condrv_get_keyinit_adr()`

## 用途
`IOCS _KEY_INIT`の処理アドレスを調べる。

## 書式
```c
#include <condrv.h>
int condrv_get_keyinit_adr(void);
```

## 解説
`condrv_get_keyinit_adr()`関数は、condrv(em).sysの内部ワークに保持されている
`IOCS _KEY_INIT`の処理アドレスを調べ、その値を返す。

`condrv_hook_keyinit()`関数でフックした後、処理アドレスを戻す場合は
この関数で現在の処理アドレスを調べ、設定したアドレスと戻り値が等しければ
`condrv_unhook_keyinit()`関数によるフック解除は成功する。
ただし、同関数でも同じチェックを行うので通常は省いてもエラーチェックを行うだけで問題ない。
他にもフックしているファンクションコールがある場合などに使用すればよい。

## 戻り値
`IOCS _KEY_INIT`の処理アドレスを返す。

エラーが発生した場合は負数を返す。

## 注意
処理アドレスはcondrv(em).sysの内部ワークに保持されているもので、
IOCSベクタテーブルに設定されているアドレスではない。

## 規格
libcondrv

## 関連項目
[condrv_hook_keyinit()](hook_keyinit.md), [condrv_unhook_keyinit()](unhook_keyinit.md)
