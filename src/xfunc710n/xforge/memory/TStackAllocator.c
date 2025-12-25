#include "xfunc710n/xforge/memory/TStackAllocator.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"
#include "xfunc710n/xforge/memory/TResourceManager.h"

struct _TStackAllocator
{
  UInt implementation;

  IAllocator *allocator;

  TResourceManager *manager;
};

typedef struct _TStackAllocator _TStackAllocator;

struct _THeader
{
  USize offset;
};

typedef struct _THeader _THeader;

struct _TLHeader
{
  USize size;
};

typedef struct _TLHeader _TLHeader;

TStackAllocator *
new_TStackAllocator(
  IAllocator *allocator,
  USize size
)
{
  if (size <= sizeof(_THeader) + sizeof(_TLHeader))
    return NULL;

  _TStackAllocator *_stackAllocator = allocate(allocator, sizeof(_TStackAllocator));

  if (_stackAllocator == NULL)
    goto exception;

  _stackAllocator->implementation = IMPLEMENTATION_TStackAllocator;

  _stackAllocator->allocator = allocator;

  _stackAllocator->manager = new_TResourceManager(_stackAllocator->allocator, size);

  if (_stackAllocator->manager == NULL)
    goto exception;

  return (TStackAllocator *) _stackAllocator;

exception:
  dispose_TStackAllocator((TStackAllocator *) _stackAllocator);
  _stackAllocator = NULL;

  return NULL;
}

void
dispose_TStackAllocator(
  TStackAllocator *stackAllocator
)
{
  _TStackAllocator *_stackAllocator = (_TStackAllocator *) stackAllocator;

  if (_stackAllocator == NULL)
    return;

  IAllocator *allocator = _stackAllocator->allocator;

  _stackAllocator->implementation = 0;

  _stackAllocator->allocator = NULL;

  if (_stackAllocator->manager != NULL) {
    dispose_TResourceManager(_stackAllocator->manager);
    _stackAllocator->manager = NULL;
  }

  deallocate(allocator, _stackAllocator);
  _stackAllocator = NULL;
}

void *
TStackAllocator_allocate(
  TStackAllocator *stackAllocator,
  USize size
)
{
  _TStackAllocator *_stackAllocator = (_TStackAllocator *) stackAllocator;

  if (size > TResourceManager_getSize(_stackAllocator->manager) - sizeof(_THeader) - sizeof(_TLHeader))
    return NULL;

  void *resource = TResourceManager_getResource(_stackAllocator->manager);

  if (
    resource == NULL ||
    ((_THeader *) resource)->offset + sizeof(_TLHeader) + size > TResourceManager_getSize(_stackAllocator->manager) - sizeof(_THeader)
  ) {
    if (TResourceManager_next(_stackAllocator->manager) == False)
      if (TResourceManager_append(_stackAllocator->manager) == False)
        return NULL;

    resource = TResourceManager_getResource(_stackAllocator->manager);
    ((_THeader *) resource)->offset = 0;
  }

  UInt8 *p = ((UInt8 *) resource) + sizeof(_THeader) + ((_THeader *) resource)->offset;
  ((_THeader *) resource)->offset += sizeof(_TLHeader) + size;
  ((_TLHeader *) p)->size = size;

  return p + sizeof(_TLHeader);
}

void
TStackAllocator_deallocate(
  TStackAllocator *stackAllocator,
  void *pointer
)
{
  _TStackAllocator *_stackAllocator = (_TStackAllocator *) stackAllocator;

  void *resource = TResourceManager_getResource(_stackAllocator->manager);

  if (resource == NULL)
    return;

  _THeader *header = (_THeader *) resource;
  UInt8 *memory = (UInt8 *) (header + 1);

  _TLHeader *pHeader = (_TLHeader *) (((UInt8 *) pointer) - sizeof(_TLHeader));
  UInt8 *pMemory = (UInt8 *) (pHeader + 1);

  if (pMemory + pHeader->size != memory + header->offset)
    return;

  header->offset -= (sizeof(_TLHeader) + pHeader->size);

  if (header->offset == 0)
    TResourceManager_back(_stackAllocator->manager);
}

void
TStackAllocator_reset(
  TStackAllocator *stackAllocator
)
{
  _TStackAllocator *_stackAllocator = (_TStackAllocator *) stackAllocator;

  if (TResourceManager_getResource(_stackAllocator->manager) == NULL)
    return;

  TResourceManager_reset(_stackAllocator->manager);
}
