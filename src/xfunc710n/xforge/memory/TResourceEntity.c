#include "xfunc710n/xforge/memory/TResourceEntity.h"

#include "xfunc710n/xforge/utility/memory/Allocator.h"

TResourceEntity *
new_TResourceEntity(
  IAllocator *allocator,
  USize size
)
{
  TResourceEntity *entity = allocate(allocator, sizeof(TResourceEntity));

  if (entity == NULL)
    goto exception;

  entity->allocator = allocator;

  entity->prv = NULL;
  entity->nxt = NULL;

  entity->size = size;

  entity->resource = allocate(allocator, size);

  if (entity->resource == NULL)
    goto exception;

  return entity;

exception:
  dispose_TResourceEntity(entity);
  entity = NULL;

  return NULL;
}

void
dispose_TResourceEntity(
  TResourceEntity *entity
)
{
  if (entity == NULL)
    return;

  IAllocator *allocator = entity->allocator;

  entity->allocator = NULL;

  entity->prv = NULL;
  entity->nxt = NULL;

  entity->size = 0;

  if (entity->resource != NULL) {
    deallocate(allocator, entity->resource);
    entity->resource = NULL;
  }

  deallocate(allocator, entity);
  entity = NULL;
}
