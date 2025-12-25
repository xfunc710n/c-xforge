#include "xfunc710n/xforge/TSShort.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSShort
{
  UInt implementation;

  SShort value;

  IAllocator *allocator;
};

typedef struct _TSShort _TSShort;

TSShort *
new_TSShort(
  IAllocator *allocator,
  SShort value
)
{
  _TSShort *_object = allocate(allocator, sizeof(_TSShort));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSShort;
  _object->value = value;
  _object->allocator = allocator;

  return (TSShort *) _object;

exception:
  dispose_TSShort((TSShort *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSShort(
  TSShort *object
)
{
  _TSShort *_object = (_TSShort *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SShort
TSShort_get(
  TSShort *object
)
{
  return ((_TSShort *) object)->value;
}

void
TSShort_set(
  TSShort *object,
  SShort value
)
{
  ((_TSShort *) object)->value = value;
}
