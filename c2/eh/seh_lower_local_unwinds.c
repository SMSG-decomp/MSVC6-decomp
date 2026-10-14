void __fastcall seh_lower_local_unwinds(c2_function *fn)

{
  c2_seh_try_scope *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_eh_tuple_cell *pcVar4;
  c2_tuple *t;
  
  for (pcVar1 = g_seh_try_records; pcVar1 != (c2_seh_try_scope *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->kind == 2) && (pcVar2 = pcVar1->finally_ret, pcVar2 != (c2_tuple *)0x0)) {
      for (pcVar4 = pcVar1->finally_calls; pcVar4 != (c2_eh_tuple_cell *)0x0; pcVar4 = pcVar4->next)
      {
        if (pcVar4->tuple != (c2_tuple *)0x0) {
          tuple_new_jmp_before(*(c2_tuple **)((int)&pcVar2->src->sym->u30 + 2),pcVar4->tuple->next);
        }
      }
    }
  }
  pcVar2 = fn->cfg->last->end;
  pcVar3 = fn->cfg->first->head->next;
  while (t = pcVar3, t != pcVar2) {
    pcVar3 = t->next;
    if ((0x187 < t->op) && (t->op < 0x18a)) {
      seh_lower_pseudo_op(t);
      tuple_unlink_free(t);
    }
  }
  return;
}

