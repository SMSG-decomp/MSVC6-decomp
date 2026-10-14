void __cdecl tmpl_finish_nonclass_template_declaration(c1_yy_value *head,c1_symbol *sym)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1xx_hash_scope *pcVar3;
  int iVar4;
  int *piVar5;
  c1xx_warning_state *pcVar6;
  c1_u32 *snapshot_word;
  bool bVar7;
  
  if (sym == (c1_symbol *)0x0) {
    return;
  }
  if (head->words[1] != 0) {
    diag_warning(1,0x207);
  }
  bVar2 = sym->kind & 0x1f;
  if ((bVar2 == 7) || (bVar2 == 8)) {
    tmpl_finish_function_template_declaration(head,sym);
  }
  else {
    decl_check_redefinition_3(&head->template_params,sym);
  }
  pcVar1 = g_arenas[0].cur;
  if ((g_tmpl_warning_state_snapshot != (int *)0x0) &&
     (g_tmpl_warning_state_snapshot[0xfa] == g_warning_state->level)) {
    iVar4 = 0xfa;
    bVar7 = true;
    piVar5 = g_tmpl_warning_state_snapshot;
    pcVar6 = g_warning_state;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *piVar5 == *(int *)pcVar6->state;
      piVar5 = piVar5 + 1;
      pcVar6 = (c1xx_warning_state *)(pcVar6->state + 4);
    } while (bVar7);
    if (bVar7) goto LAB_1044f9bc;
  }
  g_arenas[0].cur = g_arenas[0].cur + 0x3ec;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  pcVar6 = g_warning_state;
  if (pcVar1 == (c1_u8 *)0x0) {
    g_tmpl_warning_state_snapshot = (int *)0x0;
  }
  else {
    *(int *)(pcVar1 + 1000) = g_warning_state->level;
    snapshot_word = (c1_u32 *)pcVar1;
    for (iVar4 = 0xfa; g_tmpl_warning_state_snapshot = (int *)pcVar1, iVar4 != 0; iVar4 = iVar4 + -1
        ) {
      *snapshot_word = *(c1_u32 *)pcVar6->state;
      pcVar6 = (c1xx_warning_state *)(pcVar6->state + 4);
      snapshot_word = snapshot_word + 1;
    }
  }
LAB_1044f9bc:
  tmpl_set_warning_state(sym,g_tmpl_warning_state_snapshot);
  if ((sym->scope_index != 0) &&
     (pcVar3 = scope_enclosing_namespace(g_current_scope,'\x01'), pcVar3 != (c1xx_hash_scope *)0x0))
  {
    ns_check_definition_scope(&sym->kind,(int)pcVar3->ns);
  }
  return;
}

