#ifndef xfunc710n_xforge_memory_TStackAllocator
#define xfunc710n_xforge_memory_TStackAllocator

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TStackAllocator;

TStackAllocator *
new_TStackAllocator(
  IAllocator *allocator,
  USize size
);

void
dispose_TStackAllocator(
  TStackAllocator *stackAllocator
);

void *
TStackAllocator_allocate(
  TStackAllocator *stackAllocator,
  USize size
);

void
TStackAllocator_deallocate(
  TStackAllocator *stackAllocator,
  void *pointer
);

void
TStackAllocator_reset(
  TStackAllocator *stackAllocator
);

#endif
