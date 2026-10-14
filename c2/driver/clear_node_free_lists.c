void clear_node_free_lists(void)

{
  int iVar1;
  c2_node **free_list;
  
  free_list = g_node_free_lists;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *free_list = (c2_node *)0x0;
    free_list = free_list + 1;
  }
  return;
}

