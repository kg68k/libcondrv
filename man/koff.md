# `condrv_koff()`

## 用途
キー入力によるウィンドウ操作を禁止する。

## 書式
```c
#include <condrv.h>
int condrv_koff(void);
```

## 解説
`condrv_koff()`関数は、condrv(em).sysのキー入力によるウィンドウ操作を禁止する。

## 戻り値
正常終了した場合は変更前の状態を`condrv_get_keymode()`の戻り値と同じ形式で返す。

エラーが発生した場合は負数を返す。

## 規格
libcondrv

## 関連項目
[condrv_get_keymode()](get_keymode.md), [condrv_kon](kon.md)
