#ifndef xfunc710n_xforge_TUInt
#define xfunc710n_xforge_TUInt

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUInt;

TUInt *
new_TUInt(
  IAllocator *allocator,
  UInt value
);

void
dispose_TUInt(
  TUInt *object
);

UInt
TUInt_get(
  TUInt *object
);

void
TUInt_set(
  TUInt *object,
  UInt value
);

#endif
