#include "xfunc710n/xforge/TUChar.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUChar
{
  UInt implementation;

  UChar value;

  IAllocator *allocator;
};

typedef struct _TUChar _TUChar;

TUChar *
new_TUChar(
  IAllocator *allocator,
  UChar value
)
{
  _TUChar *_object = allocate(allocator, sizeof(_TUChar));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUChar;
  _object->value = value;
  _object->allocator = allocator;

  return (TUChar *) _object;

exception:
  dispose_TUChar((TUChar *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUChar(
  TUChar *object
)
{
  _TUChar *_object = (_TUChar *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UChar
TUChar_get(
  TUChar *object
)
{
  return ((_TUChar *) object)->value;
}

void
TUChar_set(
  TUChar *object,
  UChar value
)
{
  ((_TUChar *) object)->value = value;
}
