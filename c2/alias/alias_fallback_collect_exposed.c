void __fastcall alias_fallback_collect_exposed(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_symbol *pcVar2;
  c2_tuple *t;
  c2_symbol *pcVar3;
  c2_symbol_cell *cell;
  c2_symbol_cell *members;
  c2_list_cell *local_cell;
  
  pcVar1 = fn->cfg->first->head;
joined_r0x1078b5e2:
  do {
    t = pcVar1;
    if (t == (c2_tuple *)0x0) {
      return;
    }
    pcVar1 = t->next;
  } while (t->kind != '\x16');
  if (t->op != 0x1b4) goto LAB_1078b641;
  for (local_cell = (t->u14).scope_locals; local_cell != (c2_list_cell *)0x0;
      local_cell = local_cell->next) {
    pcVar2 = ((local_cell->u04).sym)->storage;
    if ((pcVar2 != (c2_symbol *)0x0) && ((pcVar2->flags5 & 2) != 0)) {
      cell = arena_alloc(1,8);
      pcVar3 = g_alias_scope_symbols;
      cell->sym = pcVar2;
      members = (pcVar3->u30).members;
      (pcVar3->u30).members = cell;
      cell->next = members;
    }
  }
  goto LAB_1078b638;
LAB_1078b641:
  if (t->op == 0x1b5) {
LAB_1078b638:
    tuple_unlink_free(t);
  }
  goto joined_r0x1078b5e2;
}

