#ifndef xfunc710n_xforge_TUSize
#define xfunc710n_xforge_TUSize

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUSize;

TUSize *
new_TUSize(
  IAllocator *allocator,
  USize value
);

void
dispose_TUSize(
  TUSize *object
);

USize
TUSize_get(
  TUSize *object
);

void
TUSize_set(
  TUSize *object,
  USize value
);

#endif
