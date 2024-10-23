// sample.c - libcondrv sample
// Copyright (C) 2024 TcbnErik

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "condrv.h"

#ifdef C23
#define UNUSED [[maybe_unused]]
#elif defined(__GNUC__) && (__GNUC__ >= 3)
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

static int kon_flag;
static int koff_flag;
static int xoff_flag;

static void sig_handler(UNUSED int sig) {
  if (xoff_flag) {
    condrv_xon();
    xoff_flag = 0;
  }
  if (kon_flag) {
    condrv_koff();
    kon_flag = 0;
  }
  if (koff_flag) {
    condrv_kon();
    koff_flag = 0;
  }

  puts("アボートしました。");
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  int keymode;

  signal(SIGINT, sig_handler);

  if (condrv_getlevel() > 0) puts("以下のメッセージは全て取り込まれません。");

  puts("ここは取り込まれます(1)。");
  condrv_xoff();
  xoff_flag = 1;
  puts("ここは取り込まれません。");
  condrv_xon();
  xoff_flag = 0;
  printf("ここは取り込まれます(2)。\n");

  keymode = condrv_get_keymode();
  if (keymode == 0) {
    printf("キー操作を不可能にしました。input return:");
    condrv_koff();
    koff_flag = 1;
    getchar();
    condrv_kon();
    koff_flag = 0;
    puts("キー操作を可能に戻しました。");
  } else if (keymode > 0) {
    printf("キー操作を可能にしました。input return:");
    condrv_kon();
    kon_flag = 1;
    getchar();
    condrv_koff();
    kon_flag = 0;
    puts("キー操作を不可能に戻しました。");
  }

  if (condrv_getver() < 0) {
    puts(
        "condrv(em).sys が組み込まれていません。"
        "XCON への書き込みテストは省略します。");
  } else {
    int i;

    puts(
        "argv[] の内容をバッファに直接書き込みます。"
        "これは必ず書き込まれます。");

    for (i = 0; i < argc; i += 1) {
      if (condrv_write(argv[i], strlen(argv[i])) < 0) {
        puts("\nXCON への書き込みに失敗しました。");
        break;
      }
      if (condrv_write((i < (argc - 1)) ? " " : "\n", 1) < 0) {
        puts("\nXCON への書き込みに失敗しました。");
        break;
      }
    }
  }

  return EXIT_SUCCESS;
}
