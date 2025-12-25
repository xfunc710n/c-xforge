#ifndef xfunc710n_xforge_TSInt
#define xfunc710n_xforge_TSInt

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TSInt;

TSInt *
new_TSInt(
  IAllocator *allocator,
  SInt value
);

void
dispose_TSInt(
  TSInt *object
);

SInt
TSInt_get(
  TSInt *object
);

void
TSInt_set(
  TSInt *object,
  SInt value
);

#endif
