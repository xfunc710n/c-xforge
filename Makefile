CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -I./include

SRC  = ./src/index.c

SRC += ./src/xfunc710n/xforge/utility/memory/Allocator.c
SRC += ./src/xfunc710n/xforge/memory/TResourceEntity.c
SRC += ./src/xfunc710n/xforge/memory/TResourceManager.c
SRC += ./src/xfunc710n/xforge/memory/IAllocator.c
SRC += ./src/xfunc710n/xforge/memory/TLinearAllocator.c
SRC += ./src/xfunc710n/xforge/memory/TStackAllocator.c
SRC += ./src/xfunc710n/xforge/memory/TPoolAllocator.c
SRC += ./src/xfunc710n/xforge/memory/TFreeListAllocator.c

SRC += ./src/xfunc710n/xforge/TSShort.c
SRC += ./src/xfunc710n/xforge/TUShort.c
SRC += ./src/xfunc710n/xforge/TSInt.c
SRC += ./src/xfunc710n/xforge/TUInt.c
SRC += ./src/xfunc710n/xforge/TSLong.c
SRC += ./src/xfunc710n/xforge/TULong.c
SRC += ./src/xfunc710n/xforge/TFloat.c
SRC += ./src/xfunc710n/xforge/TDouble.c
SRC += ./src/xfunc710n/xforge/TSInt8.c
SRC += ./src/xfunc710n/xforge/TUInt8.c
SRC += ./src/xfunc710n/xforge/TSInt16.c
SRC += ./src/xfunc710n/xforge/TUInt16.c
SRC += ./src/xfunc710n/xforge/TSInt32.c
SRC += ./src/xfunc710n/xforge/TUInt32.c
SRC += ./src/xfunc710n/xforge/TSInt64.c
SRC += ./src/xfunc710n/xforge/TUInt64.c
SRC += ./src/xfunc710n/xforge/TBoolean.c
SRC += ./src/xfunc710n/xforge/TSPointer.c
SRC += ./src/xfunc710n/xforge/TUPointer.c
SRC += ./src/xfunc710n/xforge/TUSize.c
SRC += ./src/xfunc710n/xforge/TSChar.c
SRC += ./src/xfunc710n/xforge/TUChar.c

OBJ = $(patsubst %.c,%.o,$(SRC))

debug: CFLAGS += -g
debug: all

release: all

all: clean $(OBJ)
	mkdir ./bin
	$(CC) $(CFLAGS) -o ./bin/c-xforge $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf ./bin

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
