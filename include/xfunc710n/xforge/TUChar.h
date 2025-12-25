#ifndef xfunc710n_xforge_TUChar
#define xfunc710n_xforge_TUChar

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUChar;

TUChar *
new_TUChar(
  IAllocator *allocator,
  UChar value
);

void
dispose_TUChar(
  TUChar *object
);

UChar
TUChar_get(
  TUChar *object
);

void
TUChar_set(
  TUChar *object,
  UChar value
);

#endif
