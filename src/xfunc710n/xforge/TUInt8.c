#include "xfunc710n/xforge/TUInt8.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUInt8
{
  UInt implementation;

  UInt8 value;

  IAllocator *allocator;
};

typedef struct _TUInt8 _TUInt8;

TUInt8 *
new_TUInt8(
  IAllocator *allocator,
  UInt8 value
)
{
  _TUInt8 *_object = allocate(allocator, sizeof(_TUInt8));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUInt8;
  _object->value = value;
  _object->allocator = allocator;

  return (TUInt8 *) _object;

exception:
  dispose_TUInt8((TUInt8 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUInt8(
  TUInt8 *object
)
{
  _TUInt8 *_object = (_TUInt8 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UInt8
TUInt8_get(
  TUInt8 *object
)
{
  return ((_TUInt8 *) object)->value;
}

void
TUInt8_set(
  TUInt8 *object,
  UInt8 value
)
{
  ((_TUInt8 *) object)->value = value;
}
