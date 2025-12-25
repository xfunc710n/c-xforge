#include "xfunc710n/xforge/utility/memory/Allocator.h"

#include <stdlib.h>

void *
allocate(
  IAllocator *allocator,
  USize size
)
{
  if (allocator != NULL) {
    return IAllocator_allocate(allocator, size);
  } else {
    return malloc(size);
  }
}

void
deallocate(
  IAllocator *allocator,
  void *pointer
)
{
  if (allocator != NULL) {
    IAllocator_deallocate(allocator, pointer);
  } else {
    free(pointer);
  }

  pointer = NULL;
}
