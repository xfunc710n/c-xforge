#ifndef xfunc710n_xforge_TSInt16
#define xfunc710n_xforge_TSInt16

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSInt16;

TSInt16 *
new_TSInt16(
  IAllocator *allocator,
  SInt16 value
);

void
dispose_TSInt16(
  TSInt16 *object
);

SInt16
TSInt16_get(
  TSInt16 *object
);

void
TSInt16_set(
  TSInt16 *object,
  SInt16 value
);

#endif
