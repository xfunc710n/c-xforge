#ifndef xfunc710n_xforge_memory_TResourceEntity
#define xfunc710n_xforge_memory_TResourceEntity

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"

struct TResourceEntity
{
  IAllocator *allocator;

  struct TResourceEntity *prv;
  struct TResourceEntity *nxt;

  USize size;

  void *resource;
};

typedef struct TResourceEntity TResourceEntity;

TResourceEntity *
new_TResourceEntity(
  IAllocator *allocator,
  USize size
);

void
dispose_TResourceEntity(
  TResourceEntity *entity
);

#ifdef TResourceEntity_getPrv
#error "The \"TResourceEntity_getPrv\" macro is already defined."
#endif

#ifdef TResourceEntity_getNxt
#error "The \"TResourceEntity_getNxt\" macro is already defined."
#endif

#ifdef TResourceEntity_setPrv
#error "The \"TResourceEntity_setPrv\" macro is already defined."
#endif

#ifdef TResourceEntity_setNxt
#error "The \"TResourceEntity_setNxt\" macro is already defined."
#endif

#ifdef TResourceEntity_getResource
#error "The \"TResourceEntity_getResource\" macro is already defined."
#endif

#define TResourceEntity_getPrv(entity) ((entity)->prv)

#define TResourceEntity_getNxt(entity) ((entity)->nxt)

#define TResourceEntity_setPrv(entity, val) ((entity)->prv = (val))

#define TResourceEntity_setNxt(entity, val) ((entity)->nxt = (val))

#define TResourceEntity_getResource(entity) ((entity)->resource)

static
inline
Boolean
TResourceEntity_contains(
  TResourceEntity *entity,
  void *pointer
)
{
  UPointer x = (UPointer) pointer;
  UPointer a = (UPointer) entity->resource;
  UPointer b = a + entity->size;

  return x >= a && x < b;
}

#endif
