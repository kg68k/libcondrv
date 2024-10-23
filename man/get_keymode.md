# `condrv_get_keymode()`

## 用途
キー操作の許可／禁止状態を得る。

## 書式
```c
#include <condrv.h>
int condrv_get_keymode(void);
```

## 解説
`condrv_get_keymode()`関数は、condrv(em).sysのキー入力によるウィンドウ操作が許可されているかを調べる。

## 戻り値
キー操作が許可されている場合は0を、禁止されている場合は255以下の正数(通常は0xff)を返す。

エラーが発生した場合は負数を返す。

## 規格
libcondrv

## 関連項目
[condrv_koff()](koff.md), [condrv_kon()](kon.md)
