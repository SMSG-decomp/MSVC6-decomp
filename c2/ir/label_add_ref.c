c2_label_ref * __fastcall label_add_ref(c2_tuple *label,c2_node *referrer)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  pcVar3 = (c2_operand *)node_alloc('\x1c');
  pcVar1 = label->dst;
  label->dst = pcVar3;
  pcVar2 = label->src;
  pcVar3->next = pcVar1;
  pcVar3->rank = (uint32_t)referrer;
  *(int *)&pcVar2[1].type = *(int *)&pcVar2[1].type + 1;
  return (c2_label_ref *)pcVar3;
}

