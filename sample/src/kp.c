// kp.c - libcondrv KeyPaste sample
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "condrv.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    puts("usage: kp string ...");
    return EXIT_FAILURE;
  }

  if (condrv_getver() < 0) {
    puts("condrv(em).sys が組み込まれていません。");
    return EXIT_FAILURE;
  }

  {
    char* buf = NULL;
    int len = 1;
    int i;

    for (i = 1; i < argc; i++) {
      len += strlen(argv[i]) + strlen("\r");
      if ((buf = realloc(buf, len)) == NULL) {
        puts("メモリが足りません。");
        return EXIT_FAILURE;
      }
      if (i == 1) *buf = 0;
      strcat(strcat(buf, argv[i]), "\r");
    }

    if (condrv_get_keybuf_len() <= len) {
      puts("キーペーストバッファの容量が足りません。");
      return EXIT_FAILURE;
    }
    condrv_keypaste(buf, len);
  }

  return EXIT_SUCCESS;
}
