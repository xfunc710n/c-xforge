#include "xfunc710n/xforge/TSPointer.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSPointer
{
  UInt implementation;

  SPointer value;

  IAllocator *allocator;
};

typedef struct _TSPointer _TSPointer;

TSPointer *
new_TSPointer(
  IAllocator *allocator,
  SPointer value
)
{
  _TSPointer *_object = allocate(allocator, sizeof(_TSPointer));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSPointer;
  _object->value = value;
  _object->allocator = allocator;

  return (TSPointer *) _object;

exception:
  dispose_TSPointer((TSPointer *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSPointer(
  TSPointer *object
)
{
  _TSPointer *_object = (_TSPointer *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SPointer
TSPointer_get(
  TSPointer *object
)
{
  return ((_TSPointer *) object)->value;
}

void
TSPointer_set(
  TSPointer *object,
  SPointer value
)
{
  ((_TSPointer *) object)->value = value;
}
