#include "xfunc710n/xforge/TSInt16.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSInt16
{
  UInt implementation;

  SInt16 value;

  IAllocator *allocator;
};

typedef struct _TSInt16 _TSInt16;

TSInt16 *
new_TSInt16(
  IAllocator *allocator,
  SInt16 value
)
{
  _TSInt16 *_object = allocate(allocator, sizeof(_TSInt16));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSInt16;
  _object->value = value;
  _object->allocator = allocator;

  return (TSInt16 *) _object;

exception:
  dispose_TSInt16((TSInt16 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSInt16(
  TSInt16 *object
)
{
  _TSInt16 *_object = (_TSInt16 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SInt16
TSInt16_get(
  TSInt16 *object
)
{
  return ((_TSInt16 *) object)->value;
}

void
TSInt16_set(
  TSInt16 *object,
  SInt16 value
)
{
  ((_TSInt16 *) object)->value = value;
}
