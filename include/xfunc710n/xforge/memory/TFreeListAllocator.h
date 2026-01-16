#ifndef xfunc710n_xforge_memory_TFreeListAllocator
#define xfunc710n_xforge_memory_TFreeListAllocator

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TFreeListAllocator;

TFreeListAllocator *
new_TFreeListAllocator(
  IAllocator *allocator,
  USize size
);

void
dispose_TFreeListAllocator(
  TFreeListAllocator *freeListAllocator
);

void *
TFreeListAllocator_allocate(
  TFreeListAllocator *freeListAllocator,
  USize size
);

void
TFreeListAllocator_deallocate(
  TFreeListAllocator *freeListAllocator,
  void *pointer
);

void
TFreeListAllocator_reset(
  TFreeListAllocator *freeListAllocator
);

#endif
