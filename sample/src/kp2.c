// kp2.c - libcondrv KeyPaste sample 2
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

#ifdef __HUMAN68K__
#define __DOS_INLINE__
#ifdef __LIBC__
#include <sys/dos.h>
#else
#include <x68k/dos.h>
#endif
#else
int _dos_super(int);
#endif

#define BUFFER_ADDRESS ((char*)0x2000)
#define BUFFER_SIZE (1024)

int main(int argc, char* argv[]) {
  if (argc == 1) {
    puts("usage: kp2 string ...");
    return EXIT_FAILURE;
  }

  if (condrv_stop_keypaste() < 0) {
    puts("condrv(em).sys が組み込まれていません。");
    return EXIT_FAILURE;
  }

  {
    int ssp = _dos_super(0);
    char* buf = BUFFER_ADDRESS;
    int len = 1;
    int i;

    for (i = 1; i < argc; i++) {
      len += strlen(argv[i]) + strlen("\r");
      if (len >= BUFFER_SIZE) {
        puts("文字列が長すぎます。");
        return EXIT_FAILURE;
      }
      if (i == 1) *buf = 0;
      strcat(strcat(buf, argv[i]), "\r");
    }
    _dos_super(ssp);
    condrv_keypaste_once(buf);
  }

  return EXIT_SUCCESS;
}
