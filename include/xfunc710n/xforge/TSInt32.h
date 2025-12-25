#ifndef xfunc710n_xforge_TSInt32
#define xfunc710n_xforge_TSInt32

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSInt32;

TSInt32 *
new_TSInt32(
  IAllocator *allocator,
  SInt32 value
);

void
dispose_TSInt32(
  TSInt32 *object
);

SInt32
TSInt32_get(
  TSInt32 *object
);

void
TSInt32_set(
  TSInt32 *object,
  SInt32 value
);

#endif
