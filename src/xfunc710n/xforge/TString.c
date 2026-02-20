#include "xfunc710n/xforge/TString.h"

TString *
new_TString(
  IAllocator *allocator,
  SChar *sequence,
  USize size
)
{
  return NULL;
}

void
dispose_TString(
  TString *sourceString
)
{

}

IAllocator *
TString_getAllocator(
  TString *sourceString
)
{
  return NULL;
}

SChar *
TString_getSequence(
  TString *sourceString
)
{
  return NULL;
}

USize
TString_getSize(
  TString *sourceString
)
{
  return 0;
}

UInt32
TString_getHash(
  TString *sourceString
)
{
  return NULL;
}

Boolean
TString_isEqual(
  TString *stringA,
  TString *stringB
)
{
  return False;
}

RIndex
TString_indexOf(
  TString *sourceString,
  TString *searchString,
  USize fromIndex
)
{
  RIndex rindex = {
    .option = False,
    .index  = 0
  };

  return rindex;
}

RIndex
TString_lastIndexOf(
  TString *sourceString,
  TString *searchString,
  USize toIndex
)
{
  RIndex rindex = {
    .option = False,
    .index  = 0
  };

  return rindex;
}

Boolean
TString_startsWith(
  TString *sourceString,
  TString *searchString,
  USize fromIndex
)
{
  return False;
}

Boolean
TString_endsWith(
  TString *sourceString,
  TString *searchString,
  USize toIndex
)
{
  return False;
}

TString *
TString_substring(
  IAllocator *allocator,
  TString *sourceString,
  USize fromIndex,
  USize toIndex
)
{
  return NULL;
}

TString *
TString_replace(
  IAllocator *allocator,
  TString *sourceString,
  TString *target,
  TString *replacement,
  USize fromIndex
)
{
  return NULL;
}

TString *
TString_replaceLast(
  IAllocator *allocator,
  TString *sourceString,
  TString *target,
  TString *replacement,
  USize toIndex
)
{
  return NULL;
}

TString *
TString_replaceAll(
  IAllocator *allocator,
  TString *sourceString,
  TString *target,
  TString *replacement,
  USize fromIndex,
  USize toIndex
)
{
  return NULL;
}

TString *
TString_concat(
  IAllocator *allocator,
  ...
)
{
  return NULL;
}

TString *
TString_format(
  IAllocator *allocator,
  TString *format,
  ...
)
{
  return NULL;
}

TString *
TString_join(
  IAllocator *allocator,
  TString *separator,
  ...
)
{
  return NULL;
}
