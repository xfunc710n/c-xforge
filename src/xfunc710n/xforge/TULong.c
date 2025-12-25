#include "xfunc710n/xforge/TULong.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TULong
{
  UInt implementation;

  ULong value;

  IAllocator *allocator;
};

typedef struct _TULong _TULong;

TULong *
new_TULong(
  IAllocator *allocator,
  ULong value
)
{
  _TULong *_object = allocate(allocator, sizeof(_TULong));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TULong;
  _object->value = value;
  _object->allocator = allocator;

  return (TULong *) _object;

exception:
  dispose_TULong((TULong *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TULong(
  TULong *object
)
{
  _TULong *_object = (_TULong *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

ULong
TULong_get(
  TULong *object
)
{
  return ((_TULong *) object)->value;
}

void
TULong_set(
  TULong *object,
  ULong value
)
{
  ((_TULong *) object)->value = value;
}
