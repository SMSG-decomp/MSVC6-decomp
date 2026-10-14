void __fastcall delete_status2_fact_tuples(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  
  pcVar1 = fn->cfg->last->end;
  pcVar2 = fn->cfg->first->head->next;
  while (t = pcVar2, t != pcVar1) {
    pcVar2 = t->next;
    if (t->flags13 == '\x02') {
      tuple_unlink_free(t);
    }
  }
  return;
}

