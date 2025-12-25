#include "xfunc710n/xforge/TSInt32.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSInt32
{
  UInt implementation;

  SInt32 value;

  IAllocator *allocator;
};

typedef struct _TSInt32 _TSInt32;

TSInt32 *
new_TSInt32(
  IAllocator *allocator,
  SInt32 value
)
{
  _TSInt32 *_object = allocate(allocator, sizeof(_TSInt32));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSInt32;
  _object->value = value;
  _object->allocator = allocator;

  return (TSInt32 *) _object;

exception:
  dispose_TSInt32((TSInt32 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSInt32(
  TSInt32 *object
)
{
  _TSInt32 *_object = (_TSInt32 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SInt32
TSInt32_get(
  TSInt32 *object
)
{
  return ((_TSInt32 *) object)->value;
}

void
TSInt32_set(
  TSInt32 *object,
  SInt32 value
)
{
  ((_TSInt32 *) object)->value = value;
}
