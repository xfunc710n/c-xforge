#include "xfunc710n/xforge/utility/hash/RS.h"

UInt32
hash_RS(
  UInt8 *payload,
  USize size
)
{
  UInt32 b = 378551;
  UInt32 a = 63689;
  UInt32 h = 0;

  for (USize i = 0; i < size; i++) {
    h = h * a + ((UInt8) *(payload + i));
    a = a * b;
  }

  return h;
}
