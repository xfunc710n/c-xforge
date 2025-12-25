#ifndef xfunc710n_xforge_TFloat
#define xfunc710n_xforge_TFloat

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TFloat;

TFloat *
new_TFloat(
  IAllocator *allocator,
  Float value
);

void
dispose_TFloat(
  TFloat *object
);

Float
TFloat_get(
  TFloat *object
);

void
TFloat_set(
  TFloat *object,
  Float value
);

#endif
