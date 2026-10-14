c2_operand * __fastcall operand_list_clone(c2_operand *list)

{
  c2_operand *node;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  pcVar2 = (c2_operand *)node_clone((c2_node *)list);
  node = list->next;
  pcVar1 = pcVar2;
  while (node != (c2_operand *)0x0) {
    pcVar3 = (c2_operand *)node_clone((c2_node *)node);
    node = node->next;
    pcVar1->next = pcVar3;
    pcVar3->rank = (uint32_t)pcVar1;
    pcVar1 = pcVar3;
  }
  return pcVar2;
}

