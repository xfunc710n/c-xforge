#ifndef xfunc710n_xforge_memory_TResourceManager
#define xfunc710n_xforge_memory_TResourceManager

#include "xfunc710n/xforge/xforge.h"
#include "xfunc710n/xforge/memory/IAllocator.h"
#include "xfunc710n/xforge/memory/TResourceEntity.h"

struct TResourceManager
{
  IAllocator *allocator;

  TResourceEntity *head;
  TResourceEntity *tail;
  TResourceEntity *current;

  USize size;
};

typedef struct TResourceManager TResourceManager;

TResourceManager *
new_TResourceManager(
  IAllocator *allocator,
  USize size
);

void
dispose_TResourceManager(
  TResourceManager *manager
);

#ifdef TResourceManager_getSize
#error "The \"TResourceManager_getSize\" macro is already defined."
#endif

#ifdef TResourceManager_reset
#error "The \"TResourceManager_reset\" macro is already defined."
#endif

#define TResourceManager_getSize(manager) ((manager)->size)

#define TResourceManager_reset(manager) ((manager)->current = NULL)

static
inline
Boolean
TResourceManager_next(
  TResourceManager *manager
)
{
  if (manager->head == NULL)
    return False;

  if (manager->current == NULL) {
    manager->current = manager->head;
    return True;
  }

  if (TResourceEntity_getNxt(manager->current) == NULL)
    return False;

  manager->current = TResourceEntity_getNxt(manager->current);

  return True;
}

static
inline
Boolean
TResourceManager_back(
  TResourceManager *manager
)
{
  if (manager->tail == NULL)
    return False;

  if (manager->current == NULL) {
    manager->current = manager->tail;
    return True;
  }

  if (TResourceEntity_getPrv(manager->current) == NULL)
    return False;

  manager->current = TResourceEntity_getPrv(manager->current);

  return True;
}

#ifdef TResourceManager_getResource
#error "The \"TResourceManager_getResource\" macro is already defined."
#endif

#define TResourceManager_getResource(manager) ((manager)->current != NULL ? TResourceEntity_getResource((manager)->current) : NULL)

static
inline
void *
TResourceManager_getResourceByPointer(
  TResourceManager *manager,
  void *pointer
)
{
  if (manager->current == NULL)
    return NULL;

  for (TResourceEntity *entity = manager->head; entity != NULL; entity = TResourceEntity_getNxt(entity)) {
    if (TResourceEntity_contains(entity, pointer) == True)
      return TResourceEntity_getResource(entity);

    if (entity == manager->current)
      break;
  }

  return NULL;
}

static
inline
Boolean
TResourceManager_append(
  TResourceManager *manager
)
{
  TResourceEntity *entity = new_TResourceEntity(manager->allocator, manager->size);
  if (entity == NULL)
    return False;

  if (manager->tail == NULL) {
    manager->tail = entity;
    manager->head = manager->tail;
  } else {
    TResourceEntity_setNxt(manager->tail, entity);
    TResourceEntity_setPrv(entity, manager->tail);
    manager->tail = entity;
  }

  manager->current = manager->tail;

  return True;
}

#endif
