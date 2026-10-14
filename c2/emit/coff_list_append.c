uint32_t __fastcall coff_list_append(c2_coff_list *list,void *value)

{
  c2_coff_list_chunk *pcVar1;
  uint32_t uVar2;
  c2_coff_list_chunk *pcVar3;
  
  if ((uint)list->capacity <= list->fill) {
    pcVar3 = (*g_coff_alloc_fn)((uint)list->capacity * 4 + 8);
    pcVar1 = list->last;
    list->last = pcVar3;
    list->fill = 0;
    pcVar3->next = pcVar1->next;
    pcVar1->next = pcVar3;
  }
  list->last->items[list->fill] = value;
  uVar2 = list->count + 1;
  list->fill = list->fill + 1;
  list->count = uVar2;
  return uVar2;
}

