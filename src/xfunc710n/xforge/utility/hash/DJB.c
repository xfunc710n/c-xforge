#include "xfunc710n/xforge/utility/hash/DJB.h"

UInt32
hash_DJB(
  UInt8 *payload,
  USize size
)
{
  UInt32 h = 5381;

  for (USize i = 0; i < size; i++)
    h = ((h << 5) + h) + ((UInt8) *(payload + i));

  return h;
}
