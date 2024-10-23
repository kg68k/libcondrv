# Makefile for libcondrv.a

ifeq ($(notdir $(CURDIR)),src)
$(error do not execute make in src directory)
endif

SRCDIR_MK = ../srcdir.mk
SRC_DIR = ../src
-include $(SRCDIR_MK)

U8TOSJ = u8tosj
AR = oar
ARFLAGS = -c
AS = has060
ASFLAGS = -w2 -c3

COND_A = libcondrv.a

SRCS = get_keybuf_len.s getver.s hook.s keypaste.s keypaste_once.s \
       konoff.s onoff.s pushpop.s stop_keypaste.s write.s xonoff.s \
       version.s
OBJS = $(SRCS:.s=.o)

DOCS = CHANGELOG.txt README.txt COPYING COPYING.RUNTIME
MANS = getlevel.txt getver.txt get_keybuf_len.txt get_keyinit_adr.txt get_keymode.txt \
       hook_keyinit.txt keypaste.txt keypaste_once.txt koff.txt kon.txt stop_keypaste.txt \
       unhook_keyinit.txt write.txt xoff.txt xon.txt
SAMPLES = Makefile kp.c kp2.c sample.c

ARCHIVE_FILES = include/condrv.h lib/$(COND_A) $(addprefix man/,$(MANS)) \
                $(addprefix sample/,$(SAMPLES)) sample/README.txt $(DOCS)
ARCHIVE_ZIP = libcond.zip


.PHONY: all archive clean

all: $(COND_A)

$(COND_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.s libcondrv.mac
	$(AS) $(ASFLAGS) -o $@ $<


define u8tosj
	$(U8TOSJ) < $(1) > $(2)

endef

archive:
	rm -f $(ARCHIVE_ZIP) $(ARCHIVE_FILES)
	mkdir -p include lib man sample
	$(U8TOSJ) < condrv.h >! include/condrv.h
	cp -p $(COND_A) lib/
	$(foreach file,$(MANS),$(call u8tosj,$(SRC_DIR)/../man/$(file:.txt=.md),man/$(file)))
	$(U8TOSJ) < $(SRC_DIR)/../sample/README.md > sample/README.txt
	$(foreach file,$(SAMPLES),$(call u8tosj,$(SRC_DIR)/../sample/src/$(file),sample/$(file)))
	$(U8TOSJ) < $(SRC_DIR)/../CHANGELOG.md > CHANGELOG.txt
	$(U8TOSJ) < $(SRC_DIR)/../README.md > README.txt
	cp -p $(addprefix $(SRC_DIR)/../,COPYING COPYING.RUNTIME) ./
	zip -9 $(ARCHIVE_ZIP) $(ARCHIVE_FILES)


clean:
	rm -f $(AECHIVE_FILES)
	rmdir -ps include lib man sample


# EOF
