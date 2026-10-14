uint32_t __fastcall tuple_delete(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_list_cell *pcVar3;
  uint32_t uVar4;
  c2_list_cell *pcVar5;
  c2_list_cell *pcVar6;
  
  if ((g_pending_tuples != (c2_list_cell *)0x0) &&
     (pcVar3 = g_pending_tuples, pcVar6 = (c2_list_cell *)0x0,
     g_pending_tuples != (c2_list_cell *)0x0)) {
    while (pcVar5 = pcVar3, (pcVar5->u04).tuple != t) {
      pcVar3 = pcVar5->next;
      pcVar6 = pcVar5;
      if (pcVar5->next == (c2_list_cell *)0x0) {
        uVar4 = tuple_unlink_free(t);
        return uVar4;
      }
    }
    if (pcVar6 == (c2_list_cell *)0x0) {
      g_pending_tuples = pcVar5->next;
      uVar4 = tuple_unlink_free(t);
      return uVar4;
    }
    pcVar6->next = pcVar5->next;
  }
  pcVar1 = t->prev;
  pcVar2 = t->next;
  pcVar1->next = pcVar2;
  pcVar2->prev = pcVar1;
  uVar4 = node_free((c2_node *)t);
  return uVar4;
}

