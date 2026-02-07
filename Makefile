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

SRC += ./src/xfunc710n/xforge/utility/hash/AP.c
SRC += ./src/xfunc710n/xforge/utility/hash/BKDR.c
SRC += ./src/xfunc710n/xforge/utility/hash/DEK.c
SRC += ./src/xfunc710n/xforge/utility/hash/DJB.c
SRC += ./src/xfunc710n/xforge/utility/hash/ELF.c
SRC += ./src/xfunc710n/xforge/utility/hash/JS.c
SRC += ./src/xfunc710n/xforge/utility/hash/PJW.c
SRC += ./src/xfunc710n/xforge/utility/hash/RS.c
SRC += ./src/xfunc710n/xforge/utility/hash/SDBM.c

SRC += ./src/xfunc710n/xforge/TString.c

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
