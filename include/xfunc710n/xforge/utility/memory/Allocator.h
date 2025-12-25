#ifndef xfunc710n_xforge_utility_memory_Allocator
#define xfunc710n_xforge_utility_memory_Allocator

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

void *
allocate(
  IAllocator *allocator,
  USize size
);

void
deallocate(
  IAllocator *allocator,
  void *pointer
);

#endif
