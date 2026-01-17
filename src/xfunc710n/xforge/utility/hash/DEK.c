#include "xfunc710n/xforge/utility/hash/DEK.h"

UInt32
hash_DEK(
  UInt8 *payload,
  USize size
)
{
  UInt32 h = size;

  for (USize i = 0; i < size; i++)
    h = ((h << 5) ^ (h >> 27)) ^ ((UInt8) *(payload + i));

  return h;
}
