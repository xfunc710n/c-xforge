#include "xfunc710n/xforge/utility/hash/JS.h"

UInt32
hash_JS(
  UInt8 *payload,
  USize size
)
{
  UInt32 h = 1315423911;

  for (USize i = 0; i < size; i++)
    h ^= ((h << 5) + ((UInt8) *(payload + i)) + (h >> 2));

  return h;
}
