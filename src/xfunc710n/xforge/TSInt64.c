#include "xfunc710n/xforge/TSInt64.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSInt64
{
  UInt implementation;

  SInt64 value;

  IAllocator *allocator;
};

typedef struct _TSInt64 _TSInt64;

TSInt64 *
new_TSInt64(
  IAllocator *allocator,
  SInt64 value
)
{
  _TSInt64 *_object = allocate(allocator, sizeof(_TSInt64));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSInt64;
  _object->value = value;
  _object->allocator = allocator;

  return (TSInt64 *) _object;

exception:
  dispose_TSInt64((TSInt64 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSInt64(
  TSInt64 *object
)
{
  _TSInt64 *_object = (_TSInt64 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SInt64
TSInt64_get(
  TSInt64 *object
)
{
  return ((_TSInt64 *) object)->value;
}

void
TSInt64_set(
  TSInt64 *object,
  SInt64 value
)
{
  ((_TSInt64 *) object)->value = value;
}
