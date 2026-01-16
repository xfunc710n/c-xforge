#ifndef xfunc710n_xforge_memory_TPoolAllocator
#define xfunc710n_xforge_memory_TPoolAllocator

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TPoolAllocator;

TPoolAllocator *
new_TPoolAllocator(
  IAllocator *allocator,
  USize capacity,
  USize size
);

void
dispose_TPoolAllocator(
  TPoolAllocator *poolAllocator
);

void *
TPoolAllocator_allocate(
  TPoolAllocator *poolAllocator,
  USize size
);

void
TPoolAllocator_deallocate(
  TPoolAllocator *poolAllocator,
  void *pointer
);

void
TPoolAllocator_reset(
  TPoolAllocator *poolAllocator
);

#endif
