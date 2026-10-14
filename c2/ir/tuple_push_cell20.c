void __fastcall tuple_push_cell20(c2_node *node,uint32_t cc)

{
  c2_node *pcVar1;
  c2_node *pcVar2;
  
  pcVar2 = node_alloc('\x1e');
  pcVar1 = node[2].next;
  pcVar2->rank_or_prev = cc;
  node[2].next = pcVar2;
  pcVar2->next = pcVar1;
  return;
}

