#ifndef xfunc710n_xforge_TSInt8
#define xfunc710n_xforge_TSInt8

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSInt8;

TSInt8 *
new_TSInt8(
  IAllocator *allocator,
  SInt8 value
);

void
dispose_TSInt8(
  TSInt8 *object
);

SInt8
TSInt8_get(
  TSInt8 *object
);

void
TSInt8_set(
  TSInt8 *object,
  SInt8 value
);

#endif
