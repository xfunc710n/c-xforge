#ifndef xfunc710n_xforge_TString
#define xfunc710n_xforge_TString

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TString;

TString *
new_TString(
  IAllocator *allocator,
  SChar *sequence,
  USize size
);

void
dispose_TString(
  TString *sourceString
);

IAllocator *
TString_getAllocator(
  TString *sourceString
);

SChar *
TString_getSequence(
  TString *sourceString
);

USize
TString_getSize(
  TString *sourceString
);

UInt32
TString_getHash(
  TString *sourceString
);

Boolean
TString_isEqual(
  TString *stringA,
  TString *stringB
);

RIndex
TString_indexOf(
  TString *sourceString,
  TString *searchString,
  USize fromIndex
);

RIndex
TString_lastIndexOf(
  TString *sourceString,
  TString *searchString,
  USize toIndex
);

Boolean
TString_startsWith(
  TString *sourceString,
  TString *searchString,
  USize fromIndex
);

Boolean
TString_endsWith(
  TString *sourceString,
  TString *searchString,
  USize toIndex
);

TString *
TString_substring(
  IAllocator *allocator,
  TString *sourceString,
  USize fromIndex,
  USize toIndex
);

TString *
TString_replace(
  IAllocator *allocator,
  TString *sourceString,
  TString *target,
  TString *replacement,
  USize fromIndex
);

TString *
TString_replaceLast(
  IAllocator *allocator,
  TString *sourceString,
  TString *target,
  TString *replacement,
  USize toIndex
);

TString *
TString_replaceAll(
  IAllocator *allocator,
  TString *sourceString,
  TString *target,
  TString *replacement,
  USize fromIndex,
  USize toIndex
);

TString *
TString_concat(
  IAllocator *allocator,
  ...
);

TString *
TString_format(
  IAllocator *allocator,
  TString *format,
  ...
);

TString *
TString_join(
  IAllocator *allocator,
  TString *separator,
  ...
);

//<Array> TODO
//TString_split(
//  IAllocator *allocator,
//  TString *sourceString,
//  TString *separator,
//  USize limit
//);

#endif
