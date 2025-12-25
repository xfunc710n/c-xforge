#ifndef xfunc710n_xforge_TDouble
#define xfunc710n_xforge_TDouble

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TDouble;

TDouble *
new_TDouble(
  IAllocator *allocator,
  Double value
);

void
dispose_TDouble(
  TDouble *object
);

Double
TDouble_get(
  TDouble *object
);

void
TDouble_set(
  TDouble *object,
  Double value
);

#endif
