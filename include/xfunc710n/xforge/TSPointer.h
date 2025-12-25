#ifndef xfunc710n_xforge_TSPointer
#define xfunc710n_xforge_TSPointer

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSPointer;

TSPointer *
new_TSPointer(
  IAllocator *allocator,
  SPointer value
);

void
dispose_TSPointer(
  TSPointer *object
);

SPointer
TSPointer_get(
  TSPointer *object
);

void
TSPointer_set(
  TSPointer *object,
  SPointer value
);

#endif
