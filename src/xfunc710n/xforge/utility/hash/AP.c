#include "xfunc710n/xforge/utility/hash/AP.h"

UInt32
hash_AP(
  UInt8 *payload,
  USize size
)
{
  UInt32 h = 0xAAAAAAAA;

  for (USize i = 0; i < size; i++) {
    h ^= ((i & 1) == 0) ? ( (h <<  7)  ^ ((UInt8)  *(payload + i)) * (h >> 3)) :
                          (~((h << 11) + (((UInt8) *(payload + i)) ^ (h >> 5))));
  }

  return h;
}
