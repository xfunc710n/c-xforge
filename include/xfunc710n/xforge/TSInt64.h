#ifndef xfunc710n_xforge_TSInt64
#define xfunc710n_xforge_TSInt64

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSInt64;

TSInt64 *
new_TSInt64(
  IAllocator *allocator,
  SInt64 value
);

void
dispose_TSInt64(
  TSInt64 *object
);

SInt64
TSInt64_get(
  TSInt64 *object
);

void
TSInt64_set(
  TSInt64 *object,
  SInt64 value
);

#endif
