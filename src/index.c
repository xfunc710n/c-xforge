#include "xfunc710n/xforge/xforge.h"

#include <stdio.h>
#include <string.h>

#include "xfunc710n/xforge/TString.h"

SInt
main(
  SInt    argc,
  SChar **argv
)
{
  TString *str = new_TString(NULL, "Hello World!", strlen("Hello World!"));

  for (UInt i = 0; i < TString_getSize(str); i++) {
    printf("%c", *(TString_getSequence(str) + i));
  }

  printf("\n");

  printf("%d\n", TString_getHash(str));

  return 0;
}
