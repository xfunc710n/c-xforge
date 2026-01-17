#include "xfunc710n/xforge/utility/hash/ELF.h"

UInt32
hash_ELF(
  UInt8 *payload,
  USize size
)
{
  UInt32 h = 0;
  UInt32 x = 0;

  for (USize i = 0; i < size; i++) {
    h = (h << 4) + ((UInt8) *(payload + i));

    if ((x = h & 0xF0000000L) != 0) {
      h ^= (x >> 24);
      h &= ~x;
    }
  }

  return h;
}
