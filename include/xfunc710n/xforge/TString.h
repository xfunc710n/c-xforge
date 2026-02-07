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
  TString *str
);

SChar *
TString_getSequence(
  TString *str
);

USize
TString_getSize(
  TString *str
);

UInt32
TString_getHash(
  TString *str
);

#endif
