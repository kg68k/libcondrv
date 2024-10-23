# `condrv_keypaste()`

## 用途
キーペーストバッファへデータを書き込む。

## 書式
```c
#include <condrv.h>
int condrv_keypaste(const char* buf, int size);
```

## 解説
`condrv_keypaste()`関数は、`buf`が指す領域から`size`バイト分のデータをcondrv(em).sys
のキーペーストバッファへ書き込む。

書き込んだデータは関数の実行が終了した瞬間からIOCSレベルのキー入力として処理される。

## 戻り値
成功した場合は0を返す。失敗した場合は負の値を返す。
* -1 ... キーペーストバッファの容量が足りない。
* -2 ... condrv(em).sysが組み込まれていない。

## 注意
書き込んだデータは端末の入力として扱われるので、リターンキーに相当するコードは
`LF(0x0a)`ではなく`CR(0x0d)`である。

## 規格
libcondrv

## 関連項目
[condrv_get_keybuf_len](get_keybuf_len.md), [condrv_keypaste_once](keypaste_once.md)
