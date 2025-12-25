#include "xfunc710n/xforge/TUInt32.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUInt32
{
  UInt implementation;

  UInt32 value;

  IAllocator *allocator;
};

typedef struct _TUInt32 _TUInt32;

TUInt32 *
new_TUInt32(
  IAllocator *allocator,
  UInt32 value
)
{
  _TUInt32 *_object = allocate(allocator, sizeof(_TUInt32));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUInt32;
  _object->value = value;
  _object->allocator = allocator;

  return (TUInt32 *) _object;

exception:
  dispose_TUInt32((TUInt32 *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUInt32(
  TUInt32 *object
)
{
  _TUInt32 *_object = (_TUInt32 *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UInt32
TUInt32_get(
  TUInt32 *object
)
{
  return ((_TUInt32 *) object)->value;
}

void
TUInt32_set(
  TUInt32 *object,
  UInt32 value
)
{
  ((_TUInt32 *) object)->value = value;
}
