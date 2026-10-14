uint32_t __fastcall tuple_unlink_free(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  
  pcVar1 = t->prev;
  pcVar2 = t->next;
  pcVar1->next = pcVar2;
  pcVar2->prev = pcVar1;
  uVar3 = node_free((c2_node *)t);
  return uVar3;
}

