#include "xfunc710n/xforge/memory/TFreeListAllocator.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"
#include "xfunc710n/xforge/memory/TResourceManager.h"

struct _TLHeader
{
  USize size;
  Boolean occupied;
  struct _TLHeader *prv;
  struct _TLHeader *nxt;
};

struct _TLFooter
{
  USize size;
};

typedef struct _TLHeader _TLHeader;
typedef struct _TLFooter _TLFooter;

struct _TFreeListAllocator
{
  UInt implementation;

  IAllocator *allocator;

  TResourceManager *manager;

  _TLHeader *payload;
};

typedef struct _TFreeListAllocator _TFreeListAllocator;

TFreeListAllocator *
new_TFreeListAllocator(
  IAllocator *allocator,
  USize size
)
{
  if (size <= sizeof(_TLHeader) + sizeof(_TLFooter))
    return NULL;

  _TFreeListAllocator *_freeListAllocator = allocate(allocator, sizeof(_TFreeListAllocator));

  if (_freeListAllocator == NULL)
    goto exception;

  _freeListAllocator->implementation = IMPLEMENTATION_TFreeListAllocator;

  _freeListAllocator->allocator = allocator;

  _freeListAllocator->manager = new_TResourceManager(_freeListAllocator->allocator, size);

  if (_freeListAllocator->manager == NULL)
    goto exception;

  _freeListAllocator->payload = NULL;

  return (TFreeListAllocator *) _freeListAllocator;

exception:
  dispose_TFreeListAllocator((TFreeListAllocator *) _freeListAllocator);
  _freeListAllocator = NULL;

  return NULL;
}

void
dispose_TFreeListAllocator(
  TFreeListAllocator *freeListAllocator
)
{
  _TFreeListAllocator *_freeListAllocator = (_TFreeListAllocator *) freeListAllocator;

  if (_freeListAllocator == NULL)
    return;

  IAllocator *allocator = _freeListAllocator->allocator;

  _freeListAllocator->implementation = 0;

  _freeListAllocator->allocator = NULL;

  _freeListAllocator->payload = NULL;

  if (_freeListAllocator->manager != NULL) {
    dispose_TResourceManager(_freeListAllocator->manager);
    _freeListAllocator->manager = NULL;
  }

  deallocate(allocator, _freeListAllocator);
  _freeListAllocator = NULL;
}

static
inline
_TLHeader *
_TFreeListAllocator_bestFit(
  _TFreeListAllocator *_freeListAllocator,
  USize size
)
{
  _TLHeader *cHeader = _freeListAllocator->payload;
  _TLHeader *xHeader = NULL;

  while (cHeader != NULL) {
    if (cHeader->size >= size && (xHeader == NULL || cHeader->size <= xHeader->size))
      xHeader = cHeader;

    cHeader = cHeader->nxt;
  }

  return xHeader;
}

static
inline
void
_TFreeListAllocator_split(
  _TLHeader *header,
  USize size
)
{
  USize rmnSize = header->size - size;

  if (rmnSize < sizeof(_TLHeader) + 1 + sizeof(_TLFooter))
    return;

  _TLHeader *xHeader = header;
  _TLFooter *xFooter = NULL;

  _TLHeader *yHeader = NULL;
  _TLFooter *yFooter = NULL;

  xHeader->size = size;

  xFooter = (_TLFooter *) (((UInt8 *) (xHeader + 1)) + xHeader->size);
  xFooter->size = xHeader->size;

  yHeader = (_TLHeader *) (xFooter + 1);
  yHeader->size = rmnSize - sizeof(_TLHeader) - sizeof(_TLFooter);
  yHeader->occupied = False;
  yHeader->prv = xHeader;
  yHeader->nxt = xHeader->nxt;

  yFooter = (_TLFooter *) (((UInt8 *) (yHeader + 1)) + yHeader->size);
  yFooter->size = yHeader->size;

  xHeader->nxt = yHeader;

  if (yHeader->nxt != NULL)
    yHeader->nxt->prv = yHeader;
}

void *
TFreeListAllocator_allocate(
  TFreeListAllocator *freeListAllocator,
  USize size
)
{
  _TFreeListAllocator *_freeListAllocator = (_TFreeListAllocator *) freeListAllocator;

  if (size > TResourceManager_getSize(_freeListAllocator->manager) - sizeof(_TLHeader) - sizeof(_TLFooter))
    return NULL;

  _TLHeader *xHeader = _TFreeListAllocator_bestFit(_freeListAllocator, size);

  if (xHeader == NULL) {
    if (TResourceManager_next(_freeListAllocator->manager) == False)
      if (TResourceManager_append(_freeListAllocator->manager) == False)
        return NULL;

    UInt8 *memory = (UInt8 *) TResourceManager_getResource(_freeListAllocator->manager);

    _TLHeader *nHeader = (_TLHeader *) memory;
    _TLFooter *nFooter = NULL;

    nHeader->size = TResourceManager_getSize(_freeListAllocator->manager) - sizeof(_TLHeader) - sizeof(_TLFooter);
    nHeader->occupied = False;
    nHeader->prv = NULL;
    nHeader->nxt = _freeListAllocator->payload;

    nFooter = (_TLFooter *) (((UInt8 *) (nHeader + 1)) + nHeader->size);
    nFooter->size = nHeader->size;

    if (_freeListAllocator->payload != NULL)
      _freeListAllocator->payload->prv = nHeader;

    _freeListAllocator->payload = nHeader;

    xHeader = _TFreeListAllocator_bestFit(_freeListAllocator, size);
  }

  _TFreeListAllocator_split(xHeader, size);

  if (xHeader == _freeListAllocator->payload) {
    _freeListAllocator->payload = xHeader->nxt;

    if (_freeListAllocator->payload != NULL)
      _freeListAllocator->payload->prv = NULL;
  } else {
    xHeader->prv->nxt = xHeader->nxt;

    if (xHeader->nxt != NULL)
      xHeader->nxt->prv = xHeader->prv;
  }

  xHeader->occupied = True;
  xHeader->prv = NULL;
  xHeader->nxt = NULL;

  return xHeader + 1;
}

void
TFreeListAllocator_deallocate(
  TFreeListAllocator *freeListAllocator,
  void *pointer
)
{
  _TFreeListAllocator *_freeListAllocator = (_TFreeListAllocator *) freeListAllocator;

  UInt8 *memory = (UInt8 *) TResourceManager_getResourceByPointer(_freeListAllocator->manager, pointer);

  if (memory == NULL)
    return;

  _TLHeader *pHeader = (_TLHeader *) (((UInt8 *) pointer) - sizeof(_TLHeader));
  _TLFooter *pFooter = (_TLFooter *) (((UInt8 *) (pHeader + 1)) + pHeader->size);

  UPointer bgnResource = ((UPointer) memory);
  UPointer endResource = ((UPointer) memory) + TResourceManager_getSize(_freeListAllocator->manager);

  UPointer bgnBatch = ((UPointer) pHeader);
  UPointer endBatch = ((UPointer) pFooter) + sizeof(_TLFooter);

  Boolean collisionL = bgnResource == bgnBatch;
  Boolean collisionR = endResource == endBatch;

  _TLHeader *headerL = NULL;
  _TLHeader *headerR = NULL;

  if (collisionL == False) {
    USize size = ((_TLFooter *) (((UInt8 *) pHeader) - sizeof(_TLFooter)))->size;

    headerL = ((_TLHeader *) (((UInt8 *) pHeader) - sizeof(_TLFooter) - size - sizeof(_TLHeader)));

    if (headerL->occupied == True)
      headerL = NULL;
  }

  if (collisionR == False) {
    headerR = (_TLHeader *) (((UInt8 *) pFooter) + sizeof(_TLFooter));

    if (headerR->occupied == True)
      headerR = NULL;
  }

  if (headerL == NULL && headerR == NULL) {
    pHeader->occupied = False;
    pHeader->prv = NULL;
    pHeader->nxt = _freeListAllocator->payload;

    if (_freeListAllocator->payload != NULL)
      _freeListAllocator->payload->prv = pHeader;

    _freeListAllocator->payload = pHeader;
  } else if (headerL != NULL && headerR == NULL) {
    headerL->size = headerL->size + pHeader->size + sizeof(_TLFooter) + sizeof(_TLHeader);

    _TLFooter *footerL = (_TLFooter *) (((UInt8 *) (headerL + 1)) + headerL->size);
    footerL->size = headerL->size;
  } else if (headerL == NULL && headerR != NULL) {
    pHeader->prv = headerR->prv;
    pHeader->nxt = headerR->nxt;

    if (pHeader->prv != NULL)
      pHeader->prv->nxt = pHeader;

    if (pHeader->nxt != NULL)
      pHeader->nxt->prv = pHeader;

    pHeader->occupied = False;
    pHeader->size = pHeader->size + headerR->size + sizeof(_TLFooter) + sizeof(_TLHeader);

    pFooter = (_TLFooter *) (((UInt8 *) (pHeader + 1)) + pHeader->size);
    pFooter->size = pHeader->size;

    if (_freeListAllocator->payload == headerR)
      _freeListAllocator->payload = pHeader;
  } else {
    headerL->nxt = headerR->nxt;

    if (headerL->nxt != NULL)
      headerL->nxt->prv = headerL;

    headerL->size = headerL->size + pHeader->size + headerR->size + (sizeof(_TLFooter) + sizeof(_TLHeader)) * 2;

    _TLFooter *footerL = (_TLFooter *) (((UInt8 *) (headerL + 1)) + headerL->size);
    footerL->size = headerL->size;

    if (_freeListAllocator->payload == headerR)
      _freeListAllocator->payload = headerL;
  }
}

void
TFreeListAllocator_reset(
  TFreeListAllocator *freeListAllocator
)
{
  _TFreeListAllocator *_freeListAllocator = (_TFreeListAllocator *) freeListAllocator;

  if (TResourceManager_getResource(_freeListAllocator->manager) == NULL)
    return;

  TResourceManager_reset(_freeListAllocator->manager);

  _freeListAllocator->payload = NULL;
}
