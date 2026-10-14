void __cdecl block_list_open_or_rewind(c1_byte_block_list **slot)

{
  c1_byte_block_list *pcVar1;
  c1_byte_block *pcVar2;
  
  pcVar1 = *slot;
  if (pcVar1 == (c1_byte_block_list *)0x0) {
    pcVar1 = mem_xmalloc(0x10);
    pcVar2 = mem_xmalloc(0x800);
    pcVar1->first = pcVar2;
    pcVar2->next = (c1_byte_block *)0x0;
    pcVar2->used = 0;
    *slot = pcVar1;
    block_list_rewind((int *)pcVar1);
    return;
  }
  pcVar1->first->used = 0;
  block_list_rewind((int *)pcVar1);
  return;
}

