c2_fe_symbol * __fastcall label_remove_ref(c2_tuple *label,c2_node *referrer)

{
  int32_t *piVar1;
  c2_operand *node;
  c2_fe_symbol *pcVar2;
  c2_node *pcVar3;
  c2_operand *pcVar4;
  
  node = label->dst;
  if ((c2_node *)node->rank != referrer) {
    pcVar3 = (c2_node *)node->next->rank;
    pcVar4 = node->next;
    while (pcVar3 != referrer) {
      pcVar3 = (c2_node *)pcVar4->next->rank;
      node = pcVar4;
      pcVar4 = pcVar4->next;
    }
    pcVar4 = node->next;
    node->next = pcVar4->next;
    node_free((c2_node *)pcVar4);
    pcVar2 = (c2_fe_symbol *)label->src;
    piVar1 = &pcVar2->refcount;
    *piVar1 = *piVar1 + -1;
    return pcVar2;
  }
  label->dst = node->next;
  node_free((c2_node *)node);
  pcVar2 = (c2_fe_symbol *)label->src;
  piVar1 = &pcVar2->refcount;
  *piVar1 = *piVar1 + -1;
  return pcVar2;
}

