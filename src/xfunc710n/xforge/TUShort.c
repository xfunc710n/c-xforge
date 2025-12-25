#include "xfunc710n/xforge/TUShort.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUShort
{
  UInt implementation;

  UShort value;

  IAllocator *allocator;
};

typedef struct _TUShort _TUShort;

TUShort *
new_TUShort(
  IAllocator *allocator,
  UShort value
)
{
  _TUShort *_object = allocate(allocator, sizeof(_TUShort));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUShort;
  _object->value = value;
  _object->allocator = allocator;

  return (TUShort *) _object;

exception:
  dispose_TUShort((TUShort *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUShort(
  TUShort *object
)
{
  _TUShort *_object = (_TUShort *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UShort
TUShort_get(
  TUShort *object
)
{
  return ((_TUShort *) object)->value;
}

void
TUShort_set(
  TUShort *object,
  UShort value
)
{
  ((_TUShort *) object)->value = value;
}
