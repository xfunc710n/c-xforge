#include "xfunc710n/xforge/TSLong.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSLong
{
  UInt implementation;

  SLong value;

  IAllocator *allocator;
};

typedef struct _TSLong _TSLong;

TSLong *
new_TSLong(
  IAllocator *allocator,
  SLong value
)
{
  _TSLong *_object = allocate(allocator, sizeof(_TSLong));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSLong;
  _object->value = value;
  _object->allocator = allocator;

  return (TSLong *) _object;

exception:
  dispose_TSLong((TSLong *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSLong(
  TSLong *object
)
{
  _TSLong *_object = (_TSLong *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SLong
TSLong_get(
  TSLong *object
)
{
  return ((_TSLong *) object)->value;
}

void
TSLong_set(
  TSLong *object,
  SLong value
)
{
  ((_TSLong *) object)->value = value;
}
