void __fastcall remove_unreachable_after_terminators(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *term;
  int iVar2;
  c2_tuple *pcVar3;
  
  pcVar1 = fn->cfg->last->end;
  pcVar3 = fn->cfg->first->head->next;
  while (term = pcVar3, term != pcVar1) {
    pcVar3 = term->next;
    if ((term->kind == '\x0f') ||
       (((term->kind == '\x11' && ((term->u20).cond_cells == (c2_cond_cell *)0x0)) &&
        (term->op != 0x18b)))) {
      iVar2 = delete_unreachable_after(fn,term);
      if (iVar2 != 0) {
        pcVar3 = term;
      }
      if (term->op == 0x18c) {
        mark_label_refs_for_18c(term);
      }
    }
  }
  return;
}

