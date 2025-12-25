#include "xfunc710n/xforge/TUInt16.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUInt16
{
  UInt implementation;

  UInt16 value;

  IAllocator *allocator;
};

typedef struct _TUInt16 _TUInt16;

TUInt16 *
new_TUInt16(
  IAllocator *allocator,
  UInt16 value
)
{
  _TUInt16 *_object = allocate(allocator, sizeof(_TUInt16));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUInt16;
  _object->value = value;
  _object->allocator = allocator;

  return (TUInt16 *) _object;

exception:
  dispose_TUInt16((TUInt16 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUInt16(
  TUInt16 *object
)
{
  _TUInt16 *_object = (_TUInt16 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UInt16
TUInt16_get(
  TUInt16 *object
)
{
  return ((_TUInt16 *) object)->value;
}

void
TUInt16_set(
  TUInt16 *object,
  UInt16 value
)
{
  ((_TUInt16 *) object)->value = value;
}
