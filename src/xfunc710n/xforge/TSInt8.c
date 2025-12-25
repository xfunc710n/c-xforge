#include "xfunc710n/xforge/TSInt8.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSInt8
{
  UInt implementation;

  SInt8 value;

  IAllocator *allocator;
};

typedef struct _TSInt8 _TSInt8;

TSInt8 *
new_TSInt8(
  IAllocator *allocator,
  SInt8 value
)
{
  _TSInt8 *_object = allocate(allocator, sizeof(_TSInt8));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSInt8;
  _object->value = value;
  _object->allocator = allocator;

  return (TSInt8 *) _object;

exception:
  dispose_TSInt8((TSInt8 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSInt8(
  TSInt8 *object
)
{
  _TSInt8 *_object = (_TSInt8 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SInt8
TSInt8_get(
  TSInt8 *object
)
{
  return ((_TSInt8 *) object)->value;
}

void
TSInt8_set(
  TSInt8 *object,
  SInt8 value
)
{
  ((_TSInt8 *) object)->value = value;
}
