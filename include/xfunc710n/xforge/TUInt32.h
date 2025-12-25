#ifndef xfunc710n_xforge_TUInt32
#define xfunc710n_xforge_TUInt32

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUInt32;

TUInt32 *
new_TUInt32(
  IAllocator *allocator,
  UInt32 value
);

void
dispose_TUInt32(
  TUInt32 *object
);

UInt32
TUInt32_get(
  TUInt32 *object
);

void
TUInt32_set(
  TUInt32 *object,
  UInt32 value
);

#endif
