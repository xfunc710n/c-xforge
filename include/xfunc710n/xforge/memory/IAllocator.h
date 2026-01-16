#ifndef xfunc710n_xforge_memory_IAllocator
#define xfunc710n_xforge_memory_IAllocator

#include "xfunc710n/xforge/xforge.h"

typedef struct { UInt implementation; } IAllocator;

void *
IAllocator_allocate(
  IAllocator *allocator,
  USize size
);

void
IAllocator_deallocate(
  IAllocator *allocator,
  void *pointer
);

void
IAllocator_reset(
  IAllocator *allocator
);

#endif
