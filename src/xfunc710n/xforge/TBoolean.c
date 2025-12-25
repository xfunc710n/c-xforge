#include "xfunc710n/xforge/TBoolean.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TBoolean
{
  UInt implementation;

  Boolean value;

  IAllocator *allocator;
};

typedef struct _TBoolean _TBoolean;

TBoolean *
new_TBoolean(
  IAllocator *allocator,
  Boolean value
)
{
  _TBoolean *_object = allocate(allocator, sizeof(_TBoolean));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TBoolean;
  _object->value = value;
  _object->allocator = allocator;

  return (TBoolean *) _object;

exception:
  dispose_TBoolean((TBoolean *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TBoolean(
  TBoolean *object
)
{
  _TBoolean *_object = (_TBoolean *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

Boolean
TBoolean_get(
  TBoolean *object
)
{
  return ((_TBoolean *) object)->value;
}

void
TBoolean_set(
  TBoolean *object,
  Boolean value
)
{
  ((_TBoolean *) object)->value = value;
}
