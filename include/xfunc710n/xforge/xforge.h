#ifndef xfunc710n_xforge_xforge
#define xfunc710n_xforge_xforge

#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef SShort
#error "The \"SShort\" macro is already defined."
#endif

#ifdef UShort
#error "The \"UShort\" macro is already defined."
#endif

#ifdef SInt
#error "The \"SInt\" macro is already defined."
#endif

#ifdef UInt
#error "The \"UInt\" macro is already defined."
#endif

#ifdef SLong
#error "The \"SLong\" macro is already defined."
#endif

#ifdef ULong
#error "The \"ULong\" macro is already defined."
#endif

#ifdef Float
#error "The \"Float\" macro is already defined."
#endif

#ifdef Double
#error "The \"Double\" macro is already defined."
#endif

#ifdef SInt8
#error "The \"SInt8\" macro is already defined."
#endif

#ifdef UInt8
#error "The \"UInt8\" macro is already defined."
#endif

#ifdef SInt16
#error "The \"SInt16\" macro is already defined."
#endif

#ifdef UInt16
#error "The \"UInt16\" macro is already defined."
#endif

#ifdef SInt32
#error "The \"SInt32\" macro is already defined."
#endif

#ifdef UInt32
#error "The \"UInt32\" macro is already defined."
#endif

#ifdef SInt64
#error "The \"SInt64\" macro is already defined."
#endif

#ifdef UInt64
#error "The \"UInt64\" macro is already defined."
#endif

#ifdef Boolean
#error "The \"Boolean\" macro is already defined."
#endif

#ifdef False
#error "The \"False\" macro is already defined."
#endif

#ifdef True
#error "The \"True\" macro is already defined."
#endif

#ifdef SPointer
#error "The \"SPointer\" macro is already defined."
#endif

#ifdef UPointer
#error "The \"UPointer\" macro is already defined."
#endif

#ifdef USize
#error "The \"USize\" macro is already defined."
#endif

#ifdef SChar
#error "The \"SChar\" macro is already defined."
#endif

#ifdef UChar
#error "The \"UChar\" macro is already defined."
#endif

#define SShort          short
#define UShort unsigned short

#define SInt          int
#define UInt unsigned int

#define SLong          long
#define ULong unsigned long

#define Float float

#define Double double

#define SInt8  int8_t
#define UInt8 uint8_t

#define SInt16  int16_t
#define UInt16 uint16_t

#define SInt32  int32_t
#define UInt32 uint32_t

#define SInt64  int64_t
#define UInt64 uint64_t

#define Boolean bool
#define False   0
#define True    1

#define SPointer  intptr_t
#define UPointer uintptr_t

#define USize size_t

#define SChar          char
#define UChar unsigned char

#ifdef MIN_SShort
#error "The \"MIN_SShort\" macro is already defined."
#endif

#ifdef MAX_SShort
#error "The \"MAX_SShort\" macro is already defined."
#endif

#ifdef MAX_UShort
#error "The \"MAX_UShort\" macro is already defined."
#endif

#ifdef MIN_SInt
#error "The \"MIN_SInt\" macro is already defined."
#endif

#ifdef MAX_SInt
#error "The \"MAX_SInt\" macro is already defined."
#endif

#ifdef MAX_UInt
#error "The \"MAX_UInt\" macro is already defined."
#endif

#ifdef MIN_SLong
#error "The \"MIN_SLong\" macro is already defined."
#endif

#ifdef MAX_SLong
#error "The \"MAX_SLong\" macro is already defined."
#endif

#ifdef MAX_ULong
#error "The \"MAX_ULong\" macro is already defined."
#endif

#ifdef MIN_Float
#error "The \"MIN_Float\" macro is already defined."
#endif

#ifdef MAX_Float
#error "The \"MAX_Float\" macro is already defined."
#endif

#ifdef MIN_Double
#error "The \"MIN_Double\" macro is already defined."
#endif

#ifdef MAX_Double
#error "The \"MAX_Double\" macro is already defined."
#endif

#ifdef MIN_SInt8
#error "The \"MIN_SInt8\" macro is already defined."
#endif

#ifdef MAX_SInt8
#error "The \"MAX_SInt8\" macro is already defined."
#endif

#ifdef MAX_UInt8
#error "The \"MAX_UInt8\" macro is already defined."
#endif

#ifdef MIN_SInt16
#error "The \"MIN_SInt16\" macro is already defined."
#endif

#ifdef MAX_SInt16
#error "The \"MAX_SInt16\" macro is already defined."
#endif

#ifdef MAX_UInt16
#error "The \"MAX_UInt16\" macro is already defined."
#endif

#ifdef MIN_SInt32
#error "The \"MIN_SInt32\" macro is already defined."
#endif

#ifdef MAX_SInt32
#error "The \"MAX_SInt32\" macro is already defined."
#endif

#ifdef MAX_UInt32
#error "The \"MAX_UInt32\" macro is already defined."
#endif

#ifdef MIN_SInt64
#error "The \"MIN_SInt64\" macro is already defined."
#endif

#ifdef MAX_SInt64
#error "The \"MAX_SInt64\" macro is already defined."
#endif

#ifdef MAX_UInt64
#error "The \"MAX_UInt64\" macro is already defined."
#endif

#define MIN_SShort SHRT_MIN
#define MAX_SShort SHRT_MAX
#define MAX_UShort USHRT_MAX

#define MIN_SInt INT_MIN
#define MAX_SInt INT_MAX
#define MAX_UInt UINT_MAX

#define MIN_SLong LONG_MIN
#define MAX_SLong LONG_MAX
#define MAX_ULong ULONG_MAX

#define MIN_Float FLT_MIN
#define MAX_Float FLT_MAX

#define MIN_Double DBL_MIN
#define MAX_Double DBL_MAX

#define MIN_SInt8 INT8_MIN
#define MAX_SInt8 INT8_MAX
#define MAX_UInt8 UINT8_MAX

#define MIN_SInt16 INT16_MIN
#define MAX_SInt16 INT16_MAX
#define MAX_UInt16 UINT16_MAX

#define MIN_SInt32 INT32_MIN
#define MAX_SInt32 INT32_MAX
#define MAX_UInt32 UINT32_MAX

#define MIN_SInt64 INT64_MIN
#define MAX_SInt64 INT64_MAX
#define MAX_UInt64 UINT64_MAX

#ifdef IMPLEMENTATION_TLinearAllocator
#error "The \"IMPLEMENTATION_TLinearAllocator\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_TStackAllocator
#error "The \"IMPLEMENTATION_TStackAllocator\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_TPoolAllocator
#error "The \"IMPLEMENTATION_TPoolAllocator\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_TFreeListAllocator
#error "The \"IMPLEMENTATION_TFreeListAllocator\" macro is already defined."
#endif

#define IMPLEMENTATION_TLinearAllocator 1

#define IMPLEMENTATION_TStackAllocator 2

#define IMPLEMENTATION_TPoolAllocator 3

#define IMPLEMENTATION_TFreeListAllocator 4

#ifdef IMPLEMENTATION_SShort
#error "The \"IMPLEMENTATION_TSShort\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UShort
#error "The \"IMPLEMENTATION_TUShort\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SInt
#error "The \"IMPLEMENTATION_TSInt\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UInt
#error "The \"IMPLEMENTATION_TUInt\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SLong
#error "The \"IMPLEMENTATION_TSLong\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_ULong
#error "The \"IMPLEMENTATION_TULong\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_Float
#error "The \"IMPLEMENTATION_TFloat\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_Double
#error "The \"IMPLEMENTATION_TDouble\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SInt8
#error "The \"IMPLEMENTATION_TSInt8\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UInt8
#error "The \"IMPLEMENTATION_TUInt8\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SInt16
#error "The \"IMPLEMENTATION_TSInt16\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UInt16
#error "The \"IMPLEMENTATION_TUInt16\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SInt32
#error "The \"IMPLEMENTATION_TSInt32\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UInt32
#error "The \"IMPLEMENTATION_TUInt32\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SInt64
#error "The \"IMPLEMENTATION_TSInt64\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UInt64
#error "The \"IMPLEMENTATION_TUInt64\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_Boolean
#error "The \"IMPLEMENTATION_TBoolean\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SPointer
#error "The \"IMPLEMENTATION_TSPointer\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UPointer
#error "The \"IMPLEMENTATION_TUPointer\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_USize
#error "The \"IMPLEMENTATION_TUSize\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_SChar
#error "The \"IMPLEMENTATION_TSChar\" macro is already defined."
#endif

#ifdef IMPLEMENTATION_UChar
#error "The \"IMPLEMENTATION_TUChar\" macro is already defined."
#endif

#define IMPLEMENTATION_TSShort 5

#define IMPLEMENTATION_TUShort 6

#define IMPLEMENTATION_TSInt 7

#define IMPLEMENTATION_TUInt 8

#define IMPLEMENTATION_TSLong 9

#define IMPLEMENTATION_TULong 10

#define IMPLEMENTATION_TFloat 11

#define IMPLEMENTATION_TDouble 12

#define IMPLEMENTATION_TSInt8 13

#define IMPLEMENTATION_TUInt8 14

#define IMPLEMENTATION_TSInt16 15

#define IMPLEMENTATION_TUInt16 16

#define IMPLEMENTATION_TSInt32 17

#define IMPLEMENTATION_TUInt32 18

#define IMPLEMENTATION_TSInt64 19

#define IMPLEMENTATION_TUInt64 20

#define IMPLEMENTATION_TBoolean 21

#define IMPLEMENTATION_TSPointer 22

#define IMPLEMENTATION_TUPointer 23

#define IMPLEMENTATION_TUSize 24

#define IMPLEMENTATION_TSChar 25

#define IMPLEMENTATION_TUChar 26

#endif
