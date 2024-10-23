# `condrv_getver()`

## 用途
condrv(em).sysのバージョンを調べる。

## 書式
```c
#include <condrv.h>
int condrv_getver(void);
```

## 解説
`condrv_getver()`関数は、組み込まれているcondrv(em).sysのバージョンを調べその値を返す。

## 戻り値
正常終了した場合は`int`型にパックされた4バイトの文字を返す。
バージョン`v1.09c+11`なら`'e11 '`、`+11a`なら`'e11a'`。
この値は必ず正数になる。

エラーが発生した場合は負数を返す。
* -2 ... condrv(em).sysが組み込まれていない。
* -1 ... その他のエラー。

## 規格
libcondrv

## 関連項目
[condrv_getlevel()](getlevel.md)
