#include "xfunc710n/xforge/TUSize.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUSize
{
  UInt implementation;

  USize value;

  IAllocator *allocator;
};

typedef struct _TUSize _TUSize;

TUSize *
new_TUSize(
  IAllocator *allocator,
  USize value
)
{
  _TUSize *_object = allocate(allocator, sizeof(_TUSize));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUSize;
  _object->value = value;
  _object->allocator = allocator;

  return (TUSize *) _object;

exception:
  dispose_TUSize((TUSize *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUSize(
  TUSize *object
)
{
  _TUSize *_object = (_TUSize *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

USize
TUSize_get(
  TUSize *object
)
{
  return ((_TUSize *) object)->value;
}

void
TUSize_set(
  TUSize *object,
  USize value
)
{
  ((_TUSize *) object)->value = value;
}
