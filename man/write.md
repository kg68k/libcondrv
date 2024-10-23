# `condrv_write()`

## 用途
バッファへデータを書き込む。

## 書式
```c
#include <condrv.h>
int condrv_write(const char* buf, int size);
```

## 解説
`condrv_write()`関数は、`buf`が指す領域から`size`バイト分のデータをcondrv(em).sysのバッファへ書き込む。

データ中に含まれる改行は`LF`でも`CRLF`でもcondrv(em).sysが正しく認識するので、
プログラムが意識する必要はない。

## 戻り値
成功した場合は実際に書き込んだバイト数を返し、失敗した場合は負の値を返す。
その場合のエラー番号は`_dos_open()`、`_dos_write()`、`_dos_close()`と同じものが返る。

## 注意
`condrv_write()`関数はバッファリング停止レベルに関係なく、常にバッファへの書き込みが行われる。

実際にはキャラクタデバイス`XCON`をオープンし、そのハンドルに対してDOSコールで書き込みを行っているだけである。

## 規格
libcondrv

## 関連項目
[condrv_getver()](getver.md), _dos_write()
