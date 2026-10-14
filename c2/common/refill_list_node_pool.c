void refill_list_node_pool(void)

{
  c2_list_cell *pcVar1;
  c2_list_cell *pcVar2;
  uint uVar3;
  
  g_list_node_free = arena_alloc(3,g_list_node_pool_block_size);
  uVar3 = g_list_node_pool_block_size & 0xfffffff0;
  pcVar2 = g_list_node_free + -2;
  pcVar1 = g_list_node_free;
  while (pcVar1 < (c2_list_cell *)((int)&pcVar2->next + uVar3)) {
    pcVar1->next = pcVar1 + 2;
    pcVar1 = pcVar1 + 2;
  }
  pcVar1->next = (c2_list_cell *)0x0;
  return;
}

