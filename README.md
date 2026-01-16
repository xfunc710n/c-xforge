# c-xforge

## 1. Introduction

The **c-xforge** library provides a set of allocators and functions for memory management.
The library is designed for a compiler that supports the ANSI C (C99) standard. The features and interfaces of **c-xforge** rely on the capabilities of this standard.

## 2. Macros

Data type macros and constants with data type constraints are defined in the header file `xfunc710n/xforge/xforge.h`.

## 2.1. Data Type Macros

These macros provide aliases for standard data types.

## 2.1.1. Basic Data Type Macros

| Macro | C Data Type | Description |
|--------|-------|----------|
| `SShort` | `short` | Signed short integer data type |
| `UShort` | `unsigned short` | Unsigned short integer data type |
| `SInt` | `int` | Signed integer data type |
| `UInt` | `unsigned int` | Unsigned integer data type |
| `SLong` | `long` | Signed long integer data type |
| `ULong` | `unsigned long` | Unsigned long integer data type |

## 2.1.2. Floating-Point Data Type Macros

| Macro | C Data Type | Description |
|--------|-------|----------|
| `Float` | `float` | Single-precision floating-point number |
| `Double` | `double` | Double-precision floating-point number |

## 2.1.3. Fixed-Width Data Type Macros (C99)

| Macro | C Data Type | Size | Description |
|--------|-------|--------|----------|
| `SInt8` | `int8_t` | 8 bits | Signed 8-bit integer data type |
| `UInt8` | `uint8_t` | 8 bits | Unsigned 8-bit integer data type |
| `SInt16` | `int16_t` | 16 bits | Signed 16-bit integer data type |
| `UInt16` | `uint16_t` | 16 bits | Unsigned 16-bit integer data type |
| `SInt32` | `int32_t` | 32 bits | Signed 32-bit integer data type |
| `UInt32` | `uint32_t` | 32 bits | Unsigned 32-bit integer data type |
| `SInt64` | `int64_t` | 64 bits | Signed 64-bit integer data type |
| `UInt64` | `uint64_t` | 64 bits | Unsigned 64-bit integer data type |

## 2.1.4. Boolean Data Type Macros

| Macro | Value | Description |
|--------|----------|----------|
| `Boolean` | `bool` | Boolean data type |
| `False` | `0` | Boolean "false" |
| `True` | `1` | Boolean "true" |

## 2.1.5. Pointer Data Type Macros

| Macro | C Data Type | Description |
|--------|-------|----------|
| `SPointer` | `intptr_t` | Signed data type for storing pointers |
| `UPointer` | `uintptr_t` | Unsigned data type for storing pointers |

## 2.1.6. Size and Counter Macro

| Macro | C Data Type | Description |
|--------|-------|----------|
| `USize` | `size_t` | Unsigned data type for sizes and counters |

## 2.1.7. Character Data Type Macros

| Macro | C Data Type | Description |
|--------|-------|----------|
| `SChar` | `char` | Signed character data type |
| `UChar` | `unsigned char` | Unsigned character data type |

## 2.2. Macros for Constants with Data Type Limits

These macros provide aliases to standard data type limit constants.

## 2.2.1. Macros for Basic Data Type Limit Constants

| Macro | Value | Description |
|--------|----------|----------|
| `MIN_SShort` | `SHRT_MIN` | Minimum value of `SShort` |
| `MAX_SShort` | `SHRT_MAX` | Maximum value of `SShort` |
| `MAX_UShort` | `USHRT_MAX` | Maximum value of `UShort` |
| `MIN_SInt` | `INT_MIN` | Minimum value of `SInt` |
| `MAX_SInt` | `INT_MAX` | Maximum value of `SInt` |
| `MAX_UInt` | `UINT_MAX` | Maximum value of `UInt` |
| `MIN_SLong` | `LONG_MIN` | Minimum value of `SLong` |
| `MAX_SLong` | `LONG_MAX` | Maximum value of `SLong` |
| `MAX_ULong` | `ULONG_MAX` | Maximum value of `ULong` |

## 2.2.2. Macros for Floating-Point Data Type Limit Constants

| Macro | Value | Description |
|--------|----------|----------|
| `MIN_Float` | `FLT_MIN` | Minimum positive value of `Float` |
| `MAX_Float` | `FLT_MAX` | Maximum value of `Float` |
| `MIN_Double` | `DBL_MIN` | Minimum positive value of `Double` |
| `MAX_Double` | `DBL_MAX` | Maximum value of `Double` |

## 2.2.3. Macros for Fixed-Width Data Type Limit Constants (C99)

| Macro | Value | Description |
|--------|----------|----------|
| `MIN_SInt8` | `INT8_MIN` | Minimum value of `SInt8` |
| `MAX_SInt8` | `INT8_MAX` | Maximum value of `SInt8` |
| `MAX_UInt8` | `UINT8_MAX` | Maximum value of `UInt8` |
| `MIN_SInt16` | `INT16_MIN` | Minimum value of `SInt16` |
| `MAX_SInt16` | `INT16_MAX` | Maximum value of `SInt16` |
| `MAX_UInt16` | `UINT16_MAX` | Maximum value of `UInt16` |
| `MIN_SInt32` | `INT32_MIN` | Minimum value of `SInt32` |
| `MAX_SInt32` | `INT32_MAX` | Maximum value of `SInt32` |
| `MAX_UInt32` | `UINT32_MAX` | Maximum value of `UInt32` |
| `MIN_SInt64` | `INT64_MIN` | Minimum value of `SInt64` |
| `MAX_SInt64` | `INT64_MAX` | Maximum value of `SInt64` |
| `MAX_UInt64` | `UINT64_MAX` | Maximum value of `UInt64` |

## 3. Memory Allocators

The **c-xforge** library includes four types of memory allocators (TLinearAllocator, TStackAllocator, TPoolAllocator, TFreeListAllocator) and provides an interface for using them (IAllocator).

The **implementation** field in the allocator structure determines which memory allocator implementation is being used.

| Macro | Value | Implementation |
|--------|----------|----------|
| `IMPLEMENTATION_TLinearAllocator` | `1` | TLinearAllocator |
| `IMPLEMENTATION_TStackAllocator` | `2` | TStackAllocator |
| `IMPLEMENTATION_TPoolAllocator` | `3` | TPoolAllocator |
| `IMPLEMENTATION_TFreeListAllocator` | `4` | TFreeListAllocator |

## 3.1. IAllocator Interface

The header file `xfunc710n/xforge/memory/IAllocator.h` defines the **IAllocator** memory allocator interface, which is used to abstract memory allocation and deallocation mechanisms in the **c-xforge** library.

The **IAllocator** interface allows for uniform operation with various allocator implementations (TLinearAllocator, TStackAllocator, TPoolAllocator, TFreeListAllocator).

## 3.1.1. IAllocator_allocate Function

### Description

A universal function for allocating memory via the **IAllocator** interface. Designed to request a memory block of arbitrary size from a specific allocator implementation.

### Signature

```c
void *
IAllocator_allocate(
  IAllocator *allocator,
  USize size
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface.

- `size` - number of bytes to allocate.

### Return Value

- pointer to the allocated memory (void *) / NULL on error.

## 3.1.2. IAllocator_deallocate Function

### Description

A universal function for deallocating memory via the **IAllocator** interface. Designed to free a memory block from a specific allocator implementation.

### Signature

```c
void
IAllocator_deallocate(
  IAllocator *allocator,
  void *pointer
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface.

- `pointer` - pointer to the memory block.

## 3.1.3. IAllocator_reset Function

### Description

A universal function to reset the state of the selected allocator, where all previously allocated memory remains reserved within it and is retained for subsequent reuse.

### Signature

```c
void
IAllocator_reset(
  IAllocator *allocator
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface.

## 3.2. Allocator Implementations

The **c-xforge** library offers four implementations of memory allocators - **TLinearAllocator**, **TStackAllocator**, **TPoolAllocator** and **TFreeListAllocator**.

| Memory Allocator | Header File |
|--------|----------|
| `TLinearAllocator` | `xfunc710n/xforge/memory/TLinearAllocator.h` |
| `TStackAllocator` | `xfunc710n/xforge/memory/TStackAllocator.h` |
| `TPoolAllocator` | `xfunc710n/xforge/memory/TPoolAllocator.h` |
| `TFreeListAllocator` | `xfunc710n/xforge/memory/TFreeListAllocator.h` |

All allocators operate through a unified memory system, obtaining new resource pages when required.
On top of this common foundation, each allocator implements its own memory management scheme, defining rules for allocation, deallocation and resource organization according to its specific strategy.

## 3.2.1. TLinearAllocator

The header file `xfunc710n/xforge/memory/TLinearAllocator.h` contains the definition of the linear allocator (TLinearAllocator), which implements the **IAllocator** interface.

This allocator organizes memory allocation in a sequential (linear) order and does not support selective deallocation of individual blocks. Clearing is only possible by performing a complete reset.

## 3.2.1.1. new_TLinearAllocator Function

### Description

The function creates a new **TLinearAllocator**.

### Signature

```c
TLinearAllocator *
new_TLinearAllocator(
  IAllocator *allocator,
  USize size
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface, which will be used for memory allocation. If set to **NULL**, the standard **malloc** is used.

- `size` - resource size in bytes.

### Return Value

- Pointer to **TLinearAllocator** / NULL on error.

## 3.2.1.2. dispose_TLinearAllocator Function

### Description

The function deallocates memory occupied by **TLinearAllocator** and all its internal structures.

### Signature

```c
void
dispose_TLinearAllocator(
  TLinearAllocator *linearAllocator
);
```

### Parameters

- `linearAllocator` - pointer to **TLinearAllocator**.

## 3.2.1.3. TLinearAllocator_allocate Function

### Description

Memory allocation function via **TLinearAllocator**. Designed to request a memory block of arbitrary size from **TLinearAllocator**.

### Signature

```c
void *
TLinearAllocator_allocate(
  TLinearAllocator *linearAllocator,
  USize size
);
```

### Parameters

- `linearAllocator` - pointer to **TLinearAllocator**.

- `size` - number of bytes to allocate.

### Return Value

- pointer to allocated memory (void *) / NULL on error.

## 3.2.1.4. TLinearAllocator_reset Function

### Description

Function to reset the state of **TLinearAllocator**, where all previously allocated memory remains reserved within it and is retained for subsequent reuse.

### Signature

```c
void
TLinearAllocator_reset(
  TLinearAllocator *linearAllocator
);
```

### Parameters

- `linearAllocator` - pointer to **TLinearAllocator**.

## 3.2.2. TStackAllocator

The header file `xfunc710n/xforge/memory/TStackAllocator.h` contains the definition of the stack memory allocator (TStackAllocator), which implements the **IAllocator** interface.

The stack allocator allocates memory sequentially, similar to a linear allocator, and supports deallocation in reverse order (LIFO).

## 3.2.2.1. new_TStackAllocator Function

### Description

The function creates a new **TStackAllocator**.

### Signature

```c
TStackAllocator *
new_TStackAllocator(
  IAllocator *allocator,
  USize size
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface, which will be used for memory allocation. If set to **NULL**, the standard **malloc** is used.

- `size` - resource size in bytes.

### Return Value

- Pointer to **TStackAllocator** / NULL on error.

## 3.2.2.2. dispose_TStackAllocator Function

### Description

The function deallocates memory occupied by **TStackAllocator** and all its internal structures.

### Signature

```c
void
dispose_TStackAllocator(
  TStackAllocator *stackAllocator
);
```

### Parameters

- `stackAllocator` - pointer to **TStackAllocator**.

## 3.2.2.3. TStackAllocator_allocate Function

### Description

Memory allocation function via **TStackAllocator**. Designed to request a memory block of arbitrary size from **TStackAllocator**.

### Signature

```c
void *
TStackAllocator_allocate(
  TStackAllocator *stackAllocator,
  USize size
);
```

### Parameters

- `stackAllocator` - pointer to **TStackAllocator**.

- `size` - number of bytes to allocate.

### Return Value

- pointer to allocated memory (void *) / NULL on error.

## 3.2.2.4. TStackAllocator_deallocate Function

### Description

Memory deallocation function via **TStackAllocator**. Designed to free a memory block from **TStackAllocator**.
Deallocation is performed strictly in reverse order relative to allocation (LIFO).
This means that only the most recently allocated block can be freed, and only after that, the previous ones.
This approach ensures simple and fast allocator operation but imposes a limitation: arbitrary block deallocation is not supported.

### Signature

```c
void
TStackAllocator_deallocate(
  TStackAllocator *stackAllocator,
  void *pointer
);
```

### Parameters

- `stackAllocator` - pointer to **TStackAllocator**.

- `pointer` - pointer to the memory block.

## 3.2.2.5. TStackAllocator_reset Function

### Description

Function to reset the state of **TStackAllocator**, where all previously allocated memory remains reserved within it and is retained for subsequent reuse.

### Signature

```c
void
TStackAllocator_reset(
  TStackAllocator *stackAllocator
);
```

### Parameters

- `stackAllocator` - pointer to **TStackAllocator**.

## 3.2.3. TPoolAllocator

The header file `xfunc710n/xforge/memory/TPoolAllocator.h` contains the definition of the pool-based memory allocator (TPoolAllocator), which implements the **IAllocator** interface.

The pool allocator allocates memory in blocks of equal size, which eliminates fragmentation and speeds up memory allocation and deallocation. Each block in the pool can be allocated or deallocated independently, making it suitable for scenarios with multiple objects of the same size.

## 3.2.3.1. new_TPoolAllocator Function

### Description

The function creates a new **TPoolAllocator**.

### Signature

```c
TPoolAllocator *
new_TPoolAllocator(
  IAllocator *allocator,
  USize capacity,
  USize size
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface, which will be used for memory allocation. If set to **NULL**, the standard **malloc** is used.

- `capacity` - number of blocks in the resource.

- `size` - size of each block in bytes.

### Return Value

- Pointer to **TPoolAllocator** / NULL on error.

## 3.2.3.2. dispose_TPoolAllocator Function

### Description

The function deallocates memory occupied by **TPoolAllocator** and all its internal structures.

### Signature

```c
void
dispose_TPoolAllocator(
  TPoolAllocator *poolAllocator
);
```

### Parameters

- `poolAllocator` - pointer to **TPoolAllocator**.

## 3.2.3.3. TPoolAllocator_allocate Function

### Description

Memory allocation function via **TPoolAllocator**. Designed to request a fixed-size memory block from **TPoolAllocator**.

### Signature

```c
void *
TPoolAllocator_allocate(
  TPoolAllocator *poolAllocator,
  USize size
);
```

### Parameters

- `poolAllocator` - pointer to **TPoolAllocator**.

- `size` - number of bytes to allocate. **Must be less than or equal to the block size specified when creating the pool.**

### Return Value

- pointer to allocated memory (void *) / NULL on error.

## 3.2.3.4. TPoolAllocator_deallocate Function

### Description

Memory deallocation function via **TPoolAllocator**. Designed to free a memory block from **TPoolAllocator**.

### Signature

```c
void
TPoolAllocator_deallocate(
  TPoolAllocator *poolAllocator,
  void *pointer
);
```

### Parameters

- `poolAllocator` - pointer to **TPoolAllocator**.

- `pointer` - pointer to the memory block.

## 3.2.3.5. TPoolAllocator_reset Function

### Description

Function to reset the state of **TPoolAllocator**, where all previously allocated memory remains reserved within it and is retained for subsequent reuse.

### Signature

```c
void
TPoolAllocator_reset(
  TPoolAllocator *poolAllocator
);
```

### Parameters

- `poolAllocator` - pointer to **TPoolAllocator**.

## 3.2.4. TFreeListAllocator

The header file `xfunc710n/xforge/memory/TFreeListAllocator.h` contains the definition of the free list-based memory allocator (TFreeListAllocator), which implements the **IAllocator** interface.

The free list allocator manages a memory pool by dividing it into variable-size blocks and maintaining a linked list of free blocks. This allows for efficient allocation and deallocation of different-sized blocks, minimizing fragmentation through the merging of adjacent free blocks.

## 3.2.4.1. new_TFreeListAllocator Function

### Description

The function creates a new **TFreeListAllocator**.

### Signature

```c
TFreeListAllocator *
new_TFreeListAllocator(
  IAllocator *allocator,
  USize size
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface, which will be used for memory allocation. If set to **NULL**, the standard **malloc** is used.

- `size` - resource size in bytes.

### Return Value

- Pointer to **TFreeListAllocator** / NULL on error.

## 3.2.4.2. dispose_TFreeListAllocator Function

### Description

The function deallocates memory occupied by **TFreeListAllocator** and all its internal structures.

### Signature

```c
void
dispose_TFreeListAllocator(
  TFreeListAllocator *freeListAllocator
);
```

### Parameters

- `freeListAllocator` - pointer to **TFreeListAllocator**.

## 3.2.4.3. TFreeListAllocator_allocate Function

### Description

Memory allocation function via **TFreeListAllocator**. Designed to request a memory block of arbitrary size from **TFreeListAllocator**.

### Signature

```c
void *
TFreeListAllocator_allocate(
  TFreeListAllocator *freeListAllocator,
  USize size
);
```

### Parameters

- `freeListAllocator` - pointer to **TFreeListAllocator**.

- `size` - number of bytes to allocate.

### Return Value

- pointer to allocated memory (void *) / NULL on error.

## 3.2.4.4. TFreeListAllocator_deallocate Function

### Description

Memory deallocation function via **TFreeListAllocator**. Designed to free a memory block from **TFreeListAllocator**. Upon deallocation, the allocator attempts to merge the freed block with adjacent free blocks to reduce fragmentation.

### Signature

```c
void
TFreeListAllocator_deallocate(
  TFreeListAllocator *freeListAllocator,
  void *pointer
);
```

### Parameters

- `freeListAllocator` - pointer to **TFreeListAllocator**.

- `pointer` - pointer to the memory block.

## 3.2.4.5. TFreeListAllocator_reset Function

### Description

Function to reset the state of **TFreeListAllocator**, where all previously allocated memory remains reserved within it and is retained for subsequent reuse.

### Signature

```c
void
TFreeListAllocator_reset(
  TFreeListAllocator *freeListAllocator
);
```

### Parameters

- `freeListAllocator` - pointer to **TFreeListAllocator**.

## 3.3. Memory Operations

The header file `xfunc710n/xforge/utility/memory/Allocator.h` contains helper functions for memory management in the **c-xforge** project. These functions act as a wrapper over the allocator system, allowing the use of custom **IAllocator** implementations and standard **C** language functions.

## 3.3.1. allocate Function

### Description

The standard **c-xforge** function for dynamic memory allocation. The function requests a memory block of the specified size.

### Signature

```c
void *
allocate(
  IAllocator *allocator,
  USize size
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface, which will be used for memory allocation. If set to **NULL**, the standard **malloc** is used.

- `size` - memory block size in bytes.

### Return Value

- pointer to allocated memory (void *) / NULL on error.

## 3.3.2. deallocate Function

### Description

The standard **c-xforge** function for deallocating previously allocated dynamic memory. The function accepts a pointer to a memory block and deallocates it.

### Signature

```c
void
deallocate(
  IAllocator *allocator,
  void *pointer
);
```

### Parameters

- `allocator` - pointer to an object implementing the **IAllocator** interface, which will be used for memory deallocation. If set to **NULL**, the standard **free** is used.

- `pointer` - pointer to the memory block.
