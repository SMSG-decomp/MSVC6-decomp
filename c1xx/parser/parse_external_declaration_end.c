void __cdecl parse_external_declaration_end(void)

{
  c1_u8 cVar1;
  c1xx_scope *pcVar2;
  c1_scope_stack *pcVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  
  if (g_abort_requested != 0) {
    c1xx_abort_if_running();
  }
  iVar5 = parse_error_recovery_count();
  if (iVar5 == 0) {
    arena_reset_ptr(g_arenas + 5);
  }
  pcVar3 = g_current_scope;
  g_paren_level_flags[0] = g_paren_level_flags[0] & 0xfc;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
  uVar6 = g_compile_flags_c4 & 0xfe7ffdfe;
  g_string_literal_cur = &g_string_literal_buffer;
  g_pending_parameter_scope = (c1_sym_list *)0x0;
  g_function_parameter_scope = (c1_sym_list *)0x0;
  g_pending_function_word = 0;
  g_function_context_word = 0;
  g_tmpl_current_template = (c1_symbol *)0x0;
  g_tmpl_current_instance = (c1_symbol *)0x0;
  g_tmpl_bound_scope = (c1xx_block_scope *)0x0;
  g_template_depth = 0;
  g_paren_depth = 0;
  g_pending_access_check[0] = (c1_symbol *)0x0;
  if ((g_opt_Zg == '\0') &&
     (((g_compile_flags_c4 & 0x20000) == 0 || ((g_compile_flags_c4 & 0x20) != 0)))) {
    g_compile_flags_c4 = uVar6;
    if ((g_current_scope->current != g_current_scope->global_scope) &&
       (g_current_scope->current->kind != '\0')) {
      pcVar2 = g_current_scope->current;
      cVar1 = pcVar2->kind;
      while (cVar1 != '\0') {
        pcVar3->current = pcVar2->outer;
        pcVar3->depth = pcVar3->depth + 0xff;
        pcVar2 = pcVar3->current;
        cVar1 = pcVar2->kind;
      }
      pcVar3->qual_class = (c1_symbol *)0x0;
      pcVar3->access_op = '\x01';
      pcVar3->qualified = '\0';
      pcVar3->reported = '\0';
      pcVar3->keep_aliases = '\0';
    }
    iVar5 = (*g_token_source->stream->vtbl->at_end)();
    uVar6 = g_compile_flags_c4;
    if ((iVar5 == 1) && (g_parse_context_depth == 0)) {
      if ((g_compile_flags_c4 & 0x20) != 0) {
        func_definition_end('\x01');
      }
      cVar4 = lex_fetch_pending_input();
      if (cVar4 == '\0') {
        arena_reset_ptr(g_arenas + 3);
        arena_reset_ptr(g_arenas + 2);
        iVar5 = parse_error_recovery_count();
        if (iVar5 == 0) {
          arena_reset_ptr(g_arenas + 4);
        }
      }
      func_flow_state_reset_if_used();
      uVar6 = g_compile_flags_c4;
    }
  }
  g_compile_flags_c4 = uVar6;
  return;
}

