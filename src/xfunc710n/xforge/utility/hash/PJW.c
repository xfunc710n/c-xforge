#include "xfunc710n/xforge/utility/hash/PJW.h"

UInt32
hash_PJW(
  UInt8 *payload,
  USize size
)
{
  UInt32 a = (UInt32) (sizeof(UInt32) * 8);
  UInt32 b = (UInt32) (a * 3 / 4);
  UInt32 c = (UInt32) (a / 8);
  UInt32 d = (UInt32) (0xFFFFFFFF) << (a - c);
  UInt32 h = 0;
  UInt32 t = 0;

  for (USize i = 0; i < size; i++) {
    h = (h << c) + ((UInt8) *(payload + i));

    if ((t = h & d) != 0)
      h = ((h ^ (t >> b)) & (~d));
  }

  return h;
}
