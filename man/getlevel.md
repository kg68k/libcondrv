# `condrv_getlevel()`

## 用途
バッファリング停止レベルを得る。

## 書式
```c
#include <condrv.h>
int condrv_getlevel(void);
```

## 解説
`condrv_getlevel()`関数は、組み込まれているcondrv(em).sysのバッファリング停止レベルを調べ、その値を返す。

## 戻り値
正常終了した場合は0～65535の停止レベルを返す。
この値が1以上の時はバッファへの取り込みが行われない。

エラーが発生した場合は負数を返す。

## 規格
libcondrv

## 関連項目
[condrv_xoff()](xoff.md), [condrv_xon()](xon.md)
