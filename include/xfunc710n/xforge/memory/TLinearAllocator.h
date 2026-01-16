#ifndef xfunc710n_xforge_memory_TLinearAllocator
#define xfunc710n_xforge_memory_TLinearAllocator

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TLinearAllocator;

TLinearAllocator *
new_TLinearAllocator(
  IAllocator *allocator,
  USize size
);

void
dispose_TLinearAllocator(
  TLinearAllocator *linearAllocator
);

void *
TLinearAllocator_allocate(
  TLinearAllocator *linearAllocator,
  USize size
);

void
TLinearAllocator_reset(
  TLinearAllocator *linearAllocator
);

#endif
