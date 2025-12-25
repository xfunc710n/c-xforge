#ifndef xfunc710n_xforge_TSChar
#define xfunc710n_xforge_TSChar

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSChar;

TSChar *
new_TSChar(
  IAllocator *allocator,
  SChar value
);

void
dispose_TSChar(
  TSChar *object
);

SChar
TSChar_get(
  TSChar *object
);

void
TSChar_set(
  TSChar *object,
  SChar value
);

#endif
