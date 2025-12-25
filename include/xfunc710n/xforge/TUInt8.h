#ifndef xfunc710n_xforge_TUInt8
#define xfunc710n_xforge_TUInt8

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUInt8;

TUInt8 *
new_TUInt8(
  IAllocator *allocator,
  UInt8 value
);

void
dispose_TUInt8(
  TUInt8 *object
);

UInt8
TUInt8_get(
  TUInt8 *object
);

void
TUInt8_set(
  TUInt8 *object,
  UInt8 value
);

#endif
