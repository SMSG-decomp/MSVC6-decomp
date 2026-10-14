void __fastcall default_argument_parse_in_class(c1_deferred_parse *rec)

{
  c1_u8 copy;
  c1xx_scope **ppcVar1;
  c1_scope_stack *pcVar2;
  c1_u8 *rec_00;
  c1_decl_state *pcVar3;
  c1_u8 *local_4;
  
  parse_context_push(&local_4);
  rec_00 = g_arenas[8].cur;
  pcVar2 = g_current_scope;
  copy = rec->keep_state;
  g_arenas[8].cur = g_arenas[8].cur + 0x1c;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  if (rec_00 == (c1_u8 *)0x0) {
    pcVar3 = (c1_decl_state *)0x0;
  }
  else {
    pcVar3 = decl_state_snapshot((c1_decl_state *)rec_00,pcVar2,pcVar2->saved,copy);
  }
  pcVar2->saved = pcVar3;
  pcVar2 = g_current_scope;
  ppcVar1 = &g_current_scope->global_scope;
  g_current_scope->depth = '\0';
  pcVar2->current = *ppcVar1;
  pcVar2->qual_class = (c1_symbol *)0x0;
  pcVar2->access_op = '\x01';
  pcVar2->qualified = '\0';
  pcVar2->reported = '\0';
  pcVar2->keep_aliases = '\0';
  g_member_function_class = g_scope_vector->entries[(short)rec->fn->scope_index];
  if (g_member_function_class != (c1_symbol *)0x0) {
    scope_enter_class(g_current_scope,g_member_function_class);
  }
  func_flow_state_note_3e();
  parse_translation_unit();
  expr_count_evaluated_operator();
  func_parse_state_pop(&local_4);
  return;
}

