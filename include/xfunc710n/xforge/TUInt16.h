#ifndef xfunc710n_xforge_TUInt16
#define xfunc710n_xforge_TUInt16

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUInt16;

TUInt16 *
new_TUInt16(
  IAllocator *allocator,
  UInt16 value
);

void
dispose_TUInt16(
  TUInt16 *object
);

UInt16
TUInt16_get(
  TUInt16 *object
);

void
TUInt16_set(
  TUInt16 *object,
  UInt16 value
);

#endif
