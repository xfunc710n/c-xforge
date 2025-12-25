#ifndef xfunc710n_xforge_TSShort
#define xfunc710n_xforge_TSShort

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSShort;

TSShort *
new_TSShort(
  IAllocator *allocator,
  SShort value
);

void
dispose_TSShort(
  TSShort *object
);

SShort
TSShort_get(
  TSShort *object
);

void
TSShort_set(
  TSShort *object,
  SShort value
);

#endif
