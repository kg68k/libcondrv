# `condrv_keypaste_once()`

## 用途
文字列をペーストする。

## 書式
```c
#include <condrv.h>
int condrv_keypaste_once(const char* buf);
```

## 解説
`condrv_keypaste_once()`関数は、`buf`が指す文字列をペーストする。
文字列はcondrv(em).sysのキーペーストバッファには書き込まれないので、
ペーストが終了するまでバッファを解放したり書き換えてはいけない。

書き込んだデータは関数の実行が終了した瞬間からIOCSレベルのキー入力として処理される。

## 戻り値
成功した場合は0を返す。失敗した場合は負の値を返す。
* -2 ... condrv(em).sysが組み込まれていない。

## 注意
書き込んだデータは端末の入力として扱われるので、リターンキーに相当するコードは
`LF(0x0a)`ではなく`CR(0x0d)`である。

## 規格
libcondrv

## 関連項目
[condrv_keypaste](keypaste.md), [condrv_stop_keypaste](stop_keypaste.md)
