c2_operand * __fastcall tuple_swap_first_srcs(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  pcVar1 = t->src;
  pcVar2 = pcVar1->next;
  t->src = pcVar2;
  pcVar3 = pcVar2->next;
  pcVar2->next = pcVar1;
  pcVar1->next = pcVar3;
  return pcVar1;
}

