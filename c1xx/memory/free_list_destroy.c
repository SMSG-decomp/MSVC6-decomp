void __cdecl free_list_destroy(c1_byte_block_list **list)

{
  c1_byte_block *pcVar1;
  c1_byte_block *p;
  
  if (*list != (c1_byte_block_list *)0x0) {
    p = (*list)->first;
    while (p != (c1_byte_block *)0x0) {
      pcVar1 = p->next;
      mem_free(p);
      p = pcVar1;
    }
    mem_free(*list);
    *list = (c1_byte_block_list *)0x0;
  }
  return;
}

