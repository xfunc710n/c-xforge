#ifndef xfunc710n_xforge_TUShort
#define xfunc710n_xforge_TUShort

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUShort;

TUShort *
new_TUShort(
  IAllocator *allocator,
  UShort value
);

void
dispose_TUShort(
  TUShort *object
);

UShort
TUShort_get(
  TUShort *object
);

void
TUShort_set(
  TUShort *object,
  UShort value
);

#endif
