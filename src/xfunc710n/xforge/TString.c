#include "xfunc710n/xforge/TString.h"

#include <string.h>

#include "xfunc710n/xforge/utility/memory/Allocator.h"
#include "xfunc710n/xforge/utility/hash/DEK.h"

struct _TString
{
  UInt implementation;

  IAllocator *allocator;

  SChar *sequence;
  USize size;

  UInt32 hash;
};

typedef struct _TString _TString;

TString *
new_TString(
  IAllocator *allocator,
  SChar *sequence,
  USize size
)
{
  Boolean isEmpty = sequence == NULL || size == 0;

  _TString *_str = allocate(allocator, sizeof(_TString));

  if (_str == NULL)
    goto exception;

  _str->implementation = IMPLEMENTATION_TString;

  _str->allocator = allocator;

  if (isEmpty == False) {
    _str->sequence = allocate(allocator, size);

    if (_str->sequence == NULL)
      goto exception;

    memcpy(_str->sequence, sequence, size);

    _str->size = size;

    _str->hash = hash_DEK((UInt8 *) _str->sequence, _str->size);
  } else {
    _str->sequence = NULL;

    _str->size = 0;

    _str->hash = 0;
  }

  return (TString *) _str;

exception:
  dispose_TString((TString *) _str);
  _str = NULL;

  return NULL;
}

void
dispose_TString(
  TString *str
)
{

}

SChar *
TString_getSequence(
  TString *str
)
{
  return ((_TString *) str)->sequence;
}

USize
TString_getSize(
  TString *str
)
{
  return ((_TString *) str)->size;
}

UInt32
TString_getHash(
  TString *str
)
{
  return ((_TString *) str)->hash;
}
