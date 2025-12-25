#ifndef xfunc710n_xforge_TUPointer
#define xfunc710n_xforge_TUPointer

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TUPointer;

TUPointer *
new_TUPointer(
  IAllocator *allocator,
  UPointer value
);

void
dispose_TUPointer(
  TUPointer *object
);

UPointer
TUPointer_get(
  TUPointer *object
);

void
TUPointer_set(
  TUPointer *object,
  UPointer value
);

#endif
