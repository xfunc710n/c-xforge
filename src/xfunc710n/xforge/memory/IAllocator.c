#include "xfunc710n/xforge/memory/IAllocator.h"

#include "xfunc710n/xforge/memory/TLinearAllocator.h"
#include "xfunc710n/xforge/memory/TStackAllocator.h"
#include "xfunc710n/xforge/memory/TPoolAllocator.h"
#include "xfunc710n/xforge/memory/TFreeListAllocator.h"

void *
IAllocator_allocate(
  IAllocator *allocator,
  USize size
)
{
  switch (allocator->implementation) {
    case IMPLEMENTATION_TLinearAllocator:
      return TLinearAllocator_allocate((TLinearAllocator *) allocator, size);
    case IMPLEMENTATION_TStackAllocator:
      return TStackAllocator_allocate((TStackAllocator *) allocator, size);
    case IMPLEMENTATION_TPoolAllocator:
      return TPoolAllocator_allocate((TPoolAllocator *) allocator, size);
    case IMPLEMENTATION_TFreeListAllocator:
      return TFreeListAllocator_allocate((TFreeListAllocator *) allocator, size);
    default:
      return NULL;
  }
}

void
IAllocator_deallocate(
  IAllocator *allocator,
  void *pointer
)
{
  switch (allocator->implementation) {
    case IMPLEMENTATION_TStackAllocator:
      TStackAllocator_deallocate((TStackAllocator *) allocator, pointer);
      break;
    case IMPLEMENTATION_TPoolAllocator:
      TPoolAllocator_deallocate((TPoolAllocator *) allocator, pointer);
      break;
    case IMPLEMENTATION_TFreeListAllocator:
      TFreeListAllocator_deallocate((TFreeListAllocator *) allocator, pointer);
      break;
    default:
      return;
  }
}

void
IAllocator_reset(
  IAllocator *allocator
)
{
  switch (allocator->implementation) {
    case IMPLEMENTATION_TLinearAllocator:
      TLinearAllocator_reset((TLinearAllocator *) allocator);
      break;
    case IMPLEMENTATION_TStackAllocator:
      TStackAllocator_reset((TStackAllocator *) allocator);
      break;
    case IMPLEMENTATION_TPoolAllocator:
      TPoolAllocator_reset((TPoolAllocator *) allocator);
      break;
    case IMPLEMENTATION_TFreeListAllocator:
      TFreeListAllocator_reset((TFreeListAllocator *) allocator);
      break;
    default:
      return;
  }
}
