#include "xfunc710n/xforge/utility/hash/SDBM.h"

UInt32
hash_SDBM(
  UInt8 *payload,
  USize size
)
{
  UInt32 h = 0;

  for (USize i = 0; i < size; i++)
    h = ((UInt8) *(payload + i)) + (h << 6) + (h << 16) - h;

  return h;
}
