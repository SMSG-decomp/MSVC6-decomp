void tu_external_declaration_end(void)

{
  c1_scope_object **ppcVar1;
  c1_scope_stack *pcVar2;
  int iVar3;
  
  if (g_abort_requested != 0) {
    c1_abort_if_running();
  }
  iVar3 = (*g_token_source->stream->vtbl->at_end)();
  if (iVar3 == 1) {
    iVar3 = yy_error_flag();
    if (iVar3 == 0) {
      arena_reset_ptr(g_arenas + 2);
    }
  }
  iVar3 = yy_error_flag();
  if (iVar3 == 0) {
    arena_reset_ptr(g_arenas + 3);
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfffff9ff;
  g_string_literal_cur = &g_string_literal_buffer;
  g_current_function = (c1_symbol *)0x0;
  g_pending_parameter_scope = (c1_scope_symbol_list *)0x0;
  g_function_parameter_scope = (c1_scope_symbol_list *)0x0;
  g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
  pcVar2 = g_current_scope;
  g_pending_function_word = 0;
  g_function_context_word = 0;
  if (g_error_count != 0) {
    ppcVar1 = &g_current_scope->file_scope;
    g_current_scope->depth = '\0';
    pcVar2->current = *ppcVar1;
    g_paren_depth = 0;
    g_il_block_level = '\0';
    g_block_scope_number = 0;
  }
  return;
}

