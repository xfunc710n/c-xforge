#ifndef xfunc710n_xforge_TUInt64
#define xfunc710n_xforge_TUInt64

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUInt64;

TUInt64 *
new_TUInt64(
  IAllocator *allocator,
  UInt64 value
);

void
dispose_TUInt64(
  TUInt64 *object
);

UInt64
TUInt64_get(
  TUInt64 *object
);

void
TUInt64_set(
  TUInt64 *object,
  UInt64 value
);

#endif
