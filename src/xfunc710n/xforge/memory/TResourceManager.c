#include "xfunc710n/xforge/memory/TResourceManager.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

TResourceManager *
new_TResourceManager(
  IAllocator *allocator,
  USize size
)
{
  TResourceManager *manager = allocate(allocator, sizeof(TResourceManager));

  if (manager == NULL)
    goto exception;

  manager->allocator = allocator;

  manager->head    = NULL;
  manager->tail    = NULL;
  manager->current = NULL;

  manager->size = size;

  return manager;

exception:
  dispose_TResourceManager(manager);
  manager = NULL;

  return NULL;
}

void
dispose_TResourceManager(
  TResourceManager *manager
)
{
  if (manager == NULL)
    return;

  IAllocator *allocator = manager->allocator;

  manager->allocator = NULL;

  while (manager->head != NULL) {
    TResourceEntity *entity = manager->head;

    if (manager->head == manager->tail) {
      manager->head = NULL;
      manager->tail = NULL;
    } else {
      TResourceEntity_setPrv(
        TResourceEntity_getNxt(
          manager->head
        ),
        NULL
      );
      manager->head = TResourceEntity_getNxt(manager->head);
    }

    dispose_TResourceEntity(entity);
    entity = NULL;
  }

  manager->current = NULL;

  manager->size = 0;

  deallocate(allocator, manager);
  manager = NULL;
}
