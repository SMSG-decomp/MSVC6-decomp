c2_coff_list * __fastcall coff_new_fixup_list(uint16_t capacity)

{
  c2_coff_list *pcVar1;
  c2_coff_list_chunk *pcVar2;
  
  pcVar1 = (*g_coff_alloc_fn)(0x20);
  pcVar1->capacity = capacity;
  pcVar1->fill = 0;
  pcVar1->count = 0;
  pcVar2 = (*g_coff_alloc_fn)((uint)capacity * 4 + 8);
  pcVar1->first = pcVar2;
  pcVar2->items[0] = (void *)0x0;
  pcVar1->last = pcVar2;
  pcVar1->cursor = 0;
  pcVar1->iter_index = 0;
  pcVar1->iter_chunk = (c2_coff_list_chunk *)0x0;
  return pcVar1;
}

