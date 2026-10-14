void __fastcall node_list_remove_rank(void *owner,int key)

{
  c2_node *node;
  uint32_t uVar1;
  c2_node *pcVar2;
  
  node = *(c2_node **)((int)owner + 0x20);
  if (node->rank_or_prev != key) {
    uVar1 = node->next->rank_or_prev;
    pcVar2 = node->next;
    while (uVar1 != key) {
      uVar1 = pcVar2->next->rank_or_prev;
      node = pcVar2;
      pcVar2 = pcVar2->next;
    }
    pcVar2 = node->next;
    node->next = pcVar2->next;
    node_free(pcVar2);
    return;
  }
  *(c2_node **)((int)owner + 0x20) = node->next;
  node_free(node);
  return;
}

