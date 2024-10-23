# `condrv_xoff()`

## 用途
バッファリング停止レベルを1増加させる。

## 書式
```c
#include <condrv.h>
int condrv_xoff(void);
```

## 解説
`condrv_xoff()`関数は、組み込まれているcondrv(em).sysのバッファリング停止レベルを1増加し、演算後の値を返す。

## 戻り値
正常終了した場合は0～65535の停止レベルを返す。
この値が1以上の時はバッファへの取り込みが行われない。

エラーが発生した場合は負数を返す。

## 注意
停止レベルが上限値の65535の時に`condrv_xoff()`関数を呼び出した場合はエラーを返す。

## 規格
libcondrv

## 関連項目
[condrv_getlevel()](getlevel.md), [condrv_xon()](xon.md)
