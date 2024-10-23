# `condrv_get_keybuf_len()`

## 用途
キーペーストバッファのサイズを得る。

## 書式
```c
#include <condrv.h>
int condrv_get_keybuf_len(void);
```

## 解説
`condrv_get_keybuf_len()`関数は、condrv(em).sysのキーペーストバッファの容量を調べ、
そのバイト数を返す。

## 戻り値
正常に収得できた場合は正数を返す。エラーが発生した場合は負数を返す。

## 注意
バッファに書き込む際には末尾に`NUL`文字を付ける。
このため、実際に書き込めるサイズは戻り値より1小さい。

## 規格
libcondrv

## 関連項目
[condrv_keypaste()](keypaste.md)
