#include "xfunc710n/xforge/TUPointer.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

struct _TUPointer
{
  UInt implementation;

  UPointer value;

  IAllocator *allocator;
};

typedef struct _TUPointer _TUPointer;

TUPointer *
new_TUPointer(
  IAllocator *allocator,
  UPointer value
)
{
  _TUPointer *_object = allocate(allocator, sizeof(_TUPointer));

  if (_object == NULL)
    goto exception;

  _object->implementation = IMPLEMENTATION_TUPointer;
  _object->value = value;
  _object->allocator = allocator;

  return (TUPointer *) _object;

exception:
  dispose_TUPointer((TUPointer *) _object);
  _object = NULL;

  return NULL;
}

void
dispose_TUPointer(
  TUPointer *object
)
{
  _TUPointer *_object = (_TUPointer *) object;

  if (_object == NULL)
    return;

  IAllocator *allocator = _object->allocator;

  _object->implementation = 0;
  _object->allocator = NULL;

  deallocate(allocator, _object);
  _object = NULL;
}

UPointer
TUPointer_get(
  TUPointer *object
)
{
  return ((_TUPointer *) object)->value;
}

void
TUPointer_set(
  TUPointer *object,
  UPointer value
)
{
  ((_TUPointer *) object)->value = value;
}
