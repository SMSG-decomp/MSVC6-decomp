void __fastcall set_tuple_block_links(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple_u14 cVar3;
  
  pcVar2 = fn->cfg->last->end->next;
  cVar3.arg = (void *)0x0;
  for (pcVar1 = fn->cfg->first->head; pcVar1 != pcVar2; pcVar1 = pcVar1->next) {
    if (pcVar1->kind == '\x19') {
      cVar3 = pcVar1->u14;
    }
    if ((pcVar1->flags & 1) != 0) {
      (pcVar1->u14).arg = (void *)cVar3;
    }
  }
  return;
}

