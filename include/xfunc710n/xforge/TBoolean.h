#ifndef xfunc710n_xforge_TBoolean
#define xfunc710n_xforge_TBoolean

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TBoolean;

TBoolean *
new_TBoolean(
  IAllocator *allocator,
  Boolean value
);

void
dispose_TBoolean(
  TBoolean *object
);

Boolean
TBoolean_get(
  TBoolean *object
);

void
TBoolean_set(
  TBoolean *object,
  Boolean value
);

#endif
