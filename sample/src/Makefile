# Makefile for libcondrv/sample

ifeq ($(notdir $(CURDIR)),src)
$(error do not execute make in src directory)
endif

CC = gcc2
CFLAGS = -funsigned-char -O2 -Werror -Wall -W
LIBSIGNAL = -lsignal

ifeq ($(CC),m68k-xelf-gcc)
CFLAGS = -funsigned-char -O2 -Werror -Wall -Wextra -finput-charset=cp932
endif

all: sample.x kp.x kp2.x

sample.x: sample.c
	$(CC) $(CFLAGS) -o $@ $< libcondrv.a $(LIBSIGNAL)

%.x: %.c
	$(CC) $(CFLAGS) -o $@ $< libcondrv.a


# EOF
