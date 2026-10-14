void __cdecl block_list_open_or_rewind(c1_byte_block_list **slot)

{
  c1_byte_block_list *list;
  c1_byte_block *block;
  
  list = *slot;
  if (list == (c1_byte_block_list *)0x0) {
    list = mem_xmalloc(0x10);
    block = mem_xmalloc(0x800);
    list->first = block;
    block->next = (c1_byte_block *)0x0;
    block->used = 0;
    *slot = list;
    block_list_rewind(list);
    return;
  }
  list->first->used = 0;
  block_list_rewind(list);
  return;
}

