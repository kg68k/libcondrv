# libcondrv

プログラムからcondrv(em).sysを操作するためのライブラリです。

ライセンスはGPLv3 + リンク例外です。  
無保証につき各自の責任で使用してください。

機能の詳細は[man/](man/)ディレクトリの各ファイルをご覧ください。  
[sample](sample/)ディレクトリにサンプルコードがあります。


## Functions

* `int condrv_getver (void);` ... condrv(em).sysのバージョンを調べる。
* `int condrv_getlevel (void);` ... バッファリング停止レベルを得る。
* `int condrv_xon (void);` ... バッファリング停止レベルを1減少させる。
* `int condrv_xoff (void);` ... バッファリング停止レベルを1増加させる。
* `int condrv_get_keymode (void);` ... キー操作の許可／禁止状態を得る。
* `int condrv_kon (void);` ... キー入力によるウィンドウ操作を許可する。
* `int condrv_koff (void);` ... キー入力によるウィンドウ操作を禁止する。
* `int condrv_write (const char* buf, int size);` ... バッファへデータを書き込む。
* `int condrv_get_keybuf_len (void);` ... キーペーストバッファのサイズを得る。
* `int condrv_keypaste (const char* buf, int size);` ... キーペーストバッファへデータを書き込む。
* `int condrv_keypaste_once (const char* buf);` ... 指定した文字列をペーストする。
* `int condrv_stop_keypaste (void);` ... キーペーストを中断する。
* `void* condrv_get_keyinit_adr (void);` ... `IOCS _KEY_INIT`の処理アドレスを調べる。
* `void* condrv_hook_keyinit (void* addr);` ... `IOCS _KEY_INIT`をフックする。
* `int condrv_unhook_keyinit (void* now_addr, void* orig_addr);` ... `IOCS _KEY_INIT`のフックを解除する。


## Install

ライブラリファイルとインクルードファイルをそれぞれ所定のディレクトリに置いてください。

* lib/libcondrv.a ...
  ライブラリ本体です。ライブラリディレクトリにコピーします。
* include/condrv.h ...
  C言語用ヘッダファイルです。インクルードディレクトリにコピーします。

実行ファイルを作成するときにlibcondrv.aをリンクします。


## Build

PCやネット上での取り扱いを用意にするために、src/内のファイルはUTF-8で記述されています。
X680x0上でビルドする際には、UTF-8からShift_JISへの変換が必要です。

### u8tosjを使用する方法

あらかじめ、[u8tosj](https://github.com/kg68k/u8tosj)をビルドしてインストールしておいてください。

トップディレクトリで`make`を実行してください。以下の処理が行われます。
1. build/ディレクトリの作成。
2. src/内の各ファイルをShift_JISに変換してbuild/へ保存。

次に、カレントディレクトリをbuild/に変更し、`make`を実行してください。  
実行ファイルが作成されます。

### u8tosjを使用しない方法

ファイルを適当なツールで適宜Shift_JISに変換してから`make`を実行してください。  
UTF-8のままでは正しくビルドできませんので注意してください。


## License

GNU GENERAL PUBLIC LICENSE Version 3 or later.  
\+ GCC Runtime Library Exception


## Author

TcbnErik / 立花@桑島技研  
https://github.com/kg68k/libcondrv
