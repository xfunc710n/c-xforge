#include "xfunc710n/xforge/TDouble.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TDouble
{
  UInt implementation;

  Double value;

  IAllocator *allocator;
};

typedef struct _TDouble _TDouble;

TDouble *
new_TDouble(
  IAllocator *allocator,
  Double value
)
{
  _TDouble *_object = allocate(allocator, sizeof(_TDouble));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TDouble;
  _object->value = value;
  _object->allocator = allocator;

  return (TDouble *) _object;

exception:
  dispose_TDouble((TDouble *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TDouble(
  TDouble *object
)
{
  _TDouble *_object = (_TDouble *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

Double
TDouble_get(
  TDouble *object
)
{
  return ((_TDouble *) object)->value;
}

void
TDouble_set(
  TDouble *object,
  Double value
)
{
  ((_TDouble *) object)->value = value;
}
