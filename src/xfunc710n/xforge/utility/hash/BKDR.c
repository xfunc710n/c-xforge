#include "xfunc710n/xforge/utility/hash/BKDR.h"

UInt32
hash_BKDR(
  UInt8 *payload,
  USize size
)
{
  UInt32 s = 131;
  UInt32 h = 0;

  for (USize i = 0; i < size; i++)
    h = (h * s) + ((UInt8) *(payload + i));

  return h;
}
