# `condrv_stop_keypaste()`

## 用途
ペーストを中断する。

## 書式
```c
#include <condrv.h>
int condrv_stop_keypaste(void);
```

## 解説
`condrv_stop_keypaste()`関数は、ペーストを中断して、ペースト文字列へのポインタを
condrv(em).sysが内部に確保している空文字列のアドレスに設定する。

## 戻り値
成功した場合は0を返す。失敗した場合は負の値を返す。
* -2 ... condrv(em).sysが組み込まれていない。

## 規格
libcondrv

## 関連項目
[condrv_keypaste()](keypaste.md), [condrv_keypaste_once](keypaste_once.md)
