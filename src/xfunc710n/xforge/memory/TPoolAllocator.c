#include "xfunc710n/xforge/memory/TPoolAllocator.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"
#include "xfunc710n/xforge/memory/TResourceManager.h"

struct _TLHeader
{
  Boolean occupied;
  struct _TLHeader *nxt;
};

typedef struct _TLHeader _TLHeader;

struct _TPoolAllocator
{
  UInt implementation;

  IAllocator *allocator;

  TResourceManager *manager;

  USize capacity;
  USize size;

  _TLHeader *payload;
};

typedef struct _TPoolAllocator _TPoolAllocator;

TPoolAllocator *
new_TPoolAllocator(
  IAllocator *allocator,
  USize capacity,
  USize size
)
{
  if (capacity == 0 || size == 0)
    return NULL;

  _TPoolAllocator *_poolAllocator = allocate(allocator, sizeof(_TPoolAllocator));

  if (_poolAllocator == NULL)
    goto exception;

  _poolAllocator->implementation = IMPLEMENTATION_TPoolAllocator;

  _poolAllocator->allocator = allocator;

  _poolAllocator->manager = new_TResourceManager(
    _poolAllocator->allocator,
    (sizeof(_TLHeader) + size) * capacity
  );

  if (_poolAllocator->manager == NULL)
    goto exception;

  _poolAllocator->capacity = capacity;
  _poolAllocator->size = size;

  _poolAllocator->payload = NULL;

  return (TPoolAllocator *) _poolAllocator;

exception:
  dispose_TPoolAllocator((TPoolAllocator *) _poolAllocator);
  _poolAllocator = NULL;

  return NULL;
}

void
dispose_TPoolAllocator(
  TPoolAllocator *poolAllocator
)
{
  _TPoolAllocator *_poolAllocator = (_TPoolAllocator *) poolAllocator;

  if (_poolAllocator == NULL)
    return;

  IAllocator *allocator = _poolAllocator->allocator;

  _poolAllocator->implementation = 0;

  _poolAllocator->allocator = NULL;

  _poolAllocator->capacity = 0;
  _poolAllocator->size = 0;

  _poolAllocator->payload = NULL;

  if (_poolAllocator->manager != NULL) {
    dispose_TResourceManager(_poolAllocator->manager);
    _poolAllocator->manager = NULL;
  }

  deallocate(allocator, _poolAllocator);
  _poolAllocator = NULL;
}

void *
TPoolAllocator_allocate(
  TPoolAllocator *poolAllocator,
  USize size
)
{
  _TPoolAllocator *_poolAllocator = (_TPoolAllocator *) poolAllocator;

  if (size > _poolAllocator->size)
    return NULL;

  if (
    TResourceManager_getResource(_poolAllocator->manager) == NULL ||
    _poolAllocator->payload == NULL
  ) {
    if (TResourceManager_next(_poolAllocator->manager) == False)
      if (TResourceManager_append(_poolAllocator->manager) == False)
        return NULL;

    UInt8 *memory = (UInt8 *) TResourceManager_getResource(_poolAllocator->manager);

    for (USize i = 0; i < _poolAllocator->capacity; i++) {
      _TLHeader *cHeader = (_TLHeader *) (memory + (sizeof(_TLHeader) + size) * i);
      _TLHeader *nHeader = NULL;

      if (i < _poolAllocator->capacity - 1)
        nHeader = (_TLHeader *) (memory + (sizeof(_TLHeader) + size) * (i + 1));

      cHeader->occupied = False;
      cHeader->nxt = nHeader;
    }

    _poolAllocator->payload = (_TLHeader *) memory;
  }

  _TLHeader *header       = _poolAllocator->payload;
  _poolAllocator->payload = _poolAllocator->payload->nxt;

  header->occupied = True;

  return header + 1;
}

void
TPoolAllocator_deallocate(
  TPoolAllocator *poolAllocator,
  void *pointer
)
{
  _TPoolAllocator *_poolAllocator = (_TPoolAllocator *) poolAllocator;

  if (TResourceManager_getResourceByPointer(_poolAllocator->manager, pointer) == NULL)
    return;

  _TLHeader *pHeader = (_TLHeader *) (((UInt8 *) pointer) - sizeof(_TLHeader));

  if (pHeader->occupied == False)
    return;

  pHeader->occupied = False;

  pHeader->nxt = _poolAllocator->payload;

  _poolAllocator->payload = pHeader;
}

void
TPoolAllocator_reset(
  TPoolAllocator *poolAllocator
)
{
  _TPoolAllocator *_poolAllocator = (_TPoolAllocator *) poolAllocator;

  if (TResourceManager_getResource(_poolAllocator->manager) == NULL)
    return;

  TResourceManager_reset(_poolAllocator->manager);

  _poolAllocator->payload = NULL;
}
