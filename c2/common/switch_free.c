uint32_t __fastcall switch_free(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  
  node_list_free((c2_node *)(t->u24).cases);
  pcVar1 = t->prev;
  pcVar2 = t->next;
  (t->u24).cases = (c2_switch_case *)0x0;
  pcVar1->next = pcVar2;
  pcVar2->prev = pcVar1;
  uVar3 = node_free((c2_node *)t);
  return uVar3;
}

