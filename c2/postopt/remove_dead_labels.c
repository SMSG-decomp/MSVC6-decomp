void __fastcall remove_dead_labels(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  
  pcVar1 = fn->cfg->last->end;
  pcVar2 = fn->cfg->first->head->next;
  while (t = pcVar2, t != pcVar1) {
    pcVar2 = t->next;
    if (t->kind == '\x1a') {
      label_try_remove(t);
    }
  }
  return;
}

