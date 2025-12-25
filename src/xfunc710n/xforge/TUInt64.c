#include "xfunc710n/xforge/TUInt64.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUInt64
{
  UInt implementation;

  UInt64 value;

  IAllocator *allocator;
};

typedef struct _TUInt64 _TUInt64;

TUInt64 *
new_TUInt64(
  IAllocator *allocator,
  UInt64 value
)
{
  _TUInt64 *_object = allocate(allocator, sizeof(_TUInt64));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUInt64;
  _object->value = value;
  _object->allocator = allocator;

  return (TUInt64 *) _object;

exception:
  dispose_TUInt64((TUInt64 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUInt64(
  TUInt64 *object
)
{
  _TUInt64 *_object = (_TUInt64 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UInt64
TUInt64_get(
  TUInt64 *object
)
{
  return ((_TUInt64 *) object)->value;
}

void
TUInt64_set(
  TUInt64 *object,
  UInt64 value
)
{
  ((_TUInt64 *) object)->value = value;
}
