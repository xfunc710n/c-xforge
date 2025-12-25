#ifndef xfunc710n_xforge_TULong
#define xfunc710n_xforge_TULong

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TULong;

TULong *
new_TULong(
  IAllocator *allocator,
  ULong value
);

void
dispose_TULong(
  TULong *object
);

ULong
TULong_get(
  TULong *object
);

void
TULong_set(
  TULong *object,
  ULong value
);

#endif
