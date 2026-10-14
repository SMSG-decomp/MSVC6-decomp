void __fastcall cfg_reset_single_block(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  
  pcVar1 = fn->cfg->last->end;
  pcVar2 = fn->cfg->first->head->next;
  while (t = pcVar2, t != pcVar1) {
    pcVar2 = t->next;
    if (t->kind == '\x19') {
      tuple_unlink(t);
      node_free((c2_node *)t);
    }
  }
  pcVar1 = fn->cfg->first->head;
  pcVar2 = fn->cfg->last->end;
  arena_reset(0xc);
  arena_reset(0xf);
  cfg_create(fn,pcVar1,pcVar2,0xc);
  return;
}

