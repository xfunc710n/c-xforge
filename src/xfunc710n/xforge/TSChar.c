#include "xfunc710n/xforge/TSChar.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TSChar
{
  UInt implementation;

  SChar value;

  IAllocator *allocator;
};

typedef struct _TSChar _TSChar;

TSChar *
new_TSChar(
  IAllocator *allocator,
  SChar value
)
{
  _TSChar *_object = allocate(allocator, sizeof(_TSChar));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TSChar;
  _object->value = value;
  _object->allocator = allocator;

  return (TSChar *) _object;

exception:
  dispose_TSChar((TSChar *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TSChar(
  TSChar *object
)
{
  _TSChar *_object = (_TSChar *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

SChar
TSChar_get(
  TSChar *object
)
{
  return ((_TSChar *) object)->value;
}

void
TSChar_set(
  TSChar *object,
  SChar value
)
{
  ((_TSChar *) object)->value = value;
}
