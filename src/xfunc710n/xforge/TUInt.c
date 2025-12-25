#include "xfunc710n/xforge/TUInt.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUInt
{
  UInt implementation;

  UInt value;

  IAllocator *allocator;
};

typedef struct _TUInt _TUInt;

TUInt *
new_TUInt(
  IAllocator *allocator,
  UInt value
)
{
  _TUInt *_object = allocate(allocator, sizeof(_TUInt));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUInt;
  _object->value = value;
  _object->allocator = allocator;

  return (TUInt *) _object;

exception:
  dispose_TUInt((TUInt *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUInt(
  TUInt *object
)
{
  _TUInt *_object = (_TUInt *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UInt
TUInt_get(
  TUInt *object
)
{
  return ((_TUInt *) object)->value;
}

void
TUInt_set(
  TUInt *object,
  UInt value
)
{
  ((_TUInt *) object)->value = value;
}
