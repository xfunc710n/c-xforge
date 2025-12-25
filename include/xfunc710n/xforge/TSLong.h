#ifndef xfunc710n_xforge_TSLong
#define xfunc710n_xforge_TSLong

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSLong;

TSLong *
new_TSLong(
  IAllocator *allocator,
  SLong value
);

void
dispose_TSLong(
  TSLong *object
);

SLong
TSLong_get(
  TSLong *object
);

void
TSLong_set(
  TSLong *object,
  SLong value
);

#endif
