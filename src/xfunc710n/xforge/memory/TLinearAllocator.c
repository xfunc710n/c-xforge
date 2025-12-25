#include "xfunc710n/xforge/memory/TLinearAllocator.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"
#include "xfunc710n/xforge/memory/TResourceManager.h"

struct _TLinearAllocator
{
  UInt implementation;

  IAllocator *allocator;

  TResourceManager *manager;
};

typedef struct _TLinearAllocator _TLinearAllocator;

struct _THeader
{
  USize offset;
};

typedef struct _THeader _THeader;

TLinearAllocator *
new_TLinearAllocator(
  IAllocator *allocator,
  USize size
)
{
  if (size <= sizeof(_THeader))
    return NULL;

  _TLinearAllocator *_linearAllocator = allocate(allocator, sizeof(_TLinearAllocator));

  if (_linearAllocator == NULL)
    goto exception;

  _linearAllocator->implementation = IMPLEMENTATION_TLinearAllocator;

  _linearAllocator->allocator = allocator;

  _linearAllocator->manager = new_TResourceManager(_linearAllocator->allocator, size);

  if (_linearAllocator->manager == NULL)
    goto exception;

  return (TLinearAllocator *) _linearAllocator;

exception:
  dispose_TLinearAllocator((TLinearAllocator *) _linearAllocator);
  _linearAllocator = NULL;

  return NULL;
}

void
dispose_TLinearAllocator(
  TLinearAllocator *linearAllocator
)
{
  _TLinearAllocator *_linearAllocator = (_TLinearAllocator *) linearAllocator;

  if (_linearAllocator == NULL)
    return;

  IAllocator *allocator = _linearAllocator->allocator;

  _linearAllocator->implementation = 0;

  _linearAllocator->allocator = NULL;

  if (_linearAllocator->manager != NULL) {
    dispose_TResourceManager(_linearAllocator->manager);
    _linearAllocator->manager = NULL;
  }

  deallocate(allocator, _linearAllocator);
  _linearAllocator = NULL;
}

void *
TLinearAllocator_allocate(
  TLinearAllocator *linearAllocator,
  USize size
)
{
  _TLinearAllocator *_linearAllocator = (_TLinearAllocator *) linearAllocator;

  if (size > TResourceManager_getSize(_linearAllocator->manager) - sizeof(_THeader))
    return NULL;

  void *resource = TResourceManager_getResource(_linearAllocator->manager);

  if (
    resource == NULL ||
    ((_THeader *) resource)->offset + size > TResourceManager_getSize(_linearAllocator->manager) - sizeof(_THeader)
  ) {
    if (TResourceManager_next(_linearAllocator->manager) == False)
      if (TResourceManager_append(_linearAllocator->manager) == False)
        return NULL;

    resource = TResourceManager_getResource(_linearAllocator->manager);
    ((_THeader *) resource)->offset = 0;
  }

  UInt8 *p = ((UInt8 *) resource) + sizeof(_THeader) + ((_THeader *) resource)->offset;
  ((_THeader *) resource)->offset += size;

  return p;
}

void
TLinearAllocator_reset(
  TLinearAllocator *linearAllocator
)
{
  _TLinearAllocator *_linearAllocator = (_TLinearAllocator *) linearAllocator;

  if (TResourceManager_getResource(_linearAllocator->manager) == NULL)
    return;

  TResourceManager_reset(_linearAllocator->manager);
}
