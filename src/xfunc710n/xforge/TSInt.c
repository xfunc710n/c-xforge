#include "xfunc710n/xforge/TSInt.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSInt
{
  UInt implementation;

  SInt value;

  IAllocator *allocator;
};

typedef struct _TSInt _TSInt;

TSInt *
new_TSInt(
  IAllocator *allocator,
  SInt value
)
{
  _TSInt *_object = allocate(allocator, sizeof(_TSInt));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSInt;
  _object->value = value;
  _object->allocator = allocator;

  return (TSInt *) _object;

exception:
  dispose_TSInt((TSInt *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSInt(
  TSInt *object
)
{
  _TSInt *_object = (_TSInt *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SInt
TSInt_get(
  TSInt *object
)
{
  return ((_TSInt *) object)->value;
}

void
TSInt_set(
  TSInt *object,
  SInt value
)
{
  ((_TSInt *) object)->value = value;
}
