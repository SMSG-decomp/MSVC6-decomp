void * __fastcall coff_list_next(c2_coff_list *list)

{
  uint uVar1;
  void *pvVar2;
  
  uVar1 = list->cursor;
  if (uVar1 == 0) {
    list->iter_index = 0;
    list->iter_chunk = list->first;
  }
  if (uVar1 < list->count) {
    list->cursor = uVar1 + 1;
    if ((uint)list->capacity <= list->iter_index) {
      list->iter_index = 0;
      list->iter_chunk = list->iter_chunk->next;
    }
    pvVar2 = list->iter_chunk->items[list->iter_index];
    list->iter_index = list->iter_index + 1;
    return pvVar2;
  }
  list->cursor = 0;
  return (void *)0x0;
}

