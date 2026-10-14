void __cdecl tree_list_cache_tail(c1_node *node)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  
  pcVar1 = node->right;
  if (node->right == (c1_node *)0x0) {
    node->link = node;
    return;
  }
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2->right;
  } while (pcVar1 != (c1_node *)0x0);
  node->link = pcVar2;
  return;
}

