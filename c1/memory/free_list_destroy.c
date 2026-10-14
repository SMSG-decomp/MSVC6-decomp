void __cdecl free_list_destroy(c1_byte_block_list **owner)

{
  c1_byte_block *pcVar1;
  c1_byte_block *p;
  
  if (*owner != (c1_byte_block_list *)0x0) {
    p = (*owner)->first;
    while (p != (c1_byte_block *)0x0) {
      pcVar1 = p->next;
      mem_free(p);
      p = pcVar1;
    }
    mem_free(*owner);
    *owner = (c1_byte_block_list *)0x0;
  }
  return;
}

