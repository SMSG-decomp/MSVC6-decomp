void __fastcall tuple_range_free(c2_tuple *t,c2_tuple *t2)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  
  while (t != t2) {
    pcVar1 = t->next;
    switch(t->kind) {
    case '\x11':
      branch_free(t);
      break;
    default:
      pcVar2 = t->prev;
      pcVar2->next = pcVar1;
      t->next->prev = pcVar2;
      node_free((c2_node *)t);
      break;
    case '\x13':
      switch_free(t);
      break;
    case '\x19':
      break;
    case '\x1a':
      label_delete(t);
    }
    t = pcVar1;
  }
  return;
}

