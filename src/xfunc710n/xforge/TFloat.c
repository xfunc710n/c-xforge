#include "xfunc710n/xforge/TFloat.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TFloat
{
  UInt implementation;

  Float value;

  IAllocator *allocator;
};

typedef struct _TFloat _TFloat;

TFloat *
new_TFloat(
  IAllocator *allocator,
  Float value
)
{
  _TFloat *_object = allocate(allocator, sizeof(_TFloat));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TFloat;
  _object->value = value;
  _object->allocator = allocator;

  return (TFloat *) _object;

exception:
  dispose_TFloat((TFloat *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TFloat(
  TFloat *object
)
{
  _TFloat *_object = (_TFloat *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

Float
TFloat_get(
  TFloat *object
)
{
  return ((_TFloat *) object)->value;
}

void
TFloat_set(
  TFloat *object,
  Float value
)
{
  ((_TFloat *) object)->value = value;
}
