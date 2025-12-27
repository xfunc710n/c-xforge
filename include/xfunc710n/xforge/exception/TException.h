#ifndef xfunc710n_xforge_exception_TException
#define xfunc710n_xforge_exception_TException

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

typedef struct { UInt implementation; } TException;

TException *
new_TException(
  IAllocator *allocator
);

void
dispose_TException(
  TException *exception
);

UInt
TException_getCode(
  TException *exception
);

UChar *
TException_getMessage(
  TException *exception
);

void
TException_assign(
  TException *exception,
  UInt code,
  UChar *message
);

#endif
