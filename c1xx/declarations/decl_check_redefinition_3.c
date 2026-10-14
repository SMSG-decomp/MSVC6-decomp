void __cdecl decl_check_redefinition_3(c1_sym_list **template_params,c1_symbol *sym)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  
  if (sym != (c1_symbol *)0x0) {
    sym->flags3 = sym->flags3 | 1;
    if ((sym->flags2 & 4) == 0) {
      sym->flags2 = sym->flags2 | 4;
    }
    else {
      diag_error(0x56,sym);
      sym->flags3 = sym->flags3 | 4;
    }
    tmpl_record_definition
              (sym,*template_params,g_tmpl_definition_tokens,g_tmpl_definition_tail_tokens);
  }
  g_compile_flags_cc = g_compile_flags_cc & 0xffdfffff;
  g_tmpl_definition_tail_tokens = (c1xx_token_stream *)0x0;
  g_tmpl_definition_tokens = (c1xx_token_stream *)0x0;
  if ((g_compile_flags_c8 & 0x80000000) != 0) {
    if (g_token_save_frame != (c1_token_source_frame *)0x0) {
      ppcVar1 = &g_token_save_frame->prev;
      g_token_record_position = g_token_save_frame->position;
      pp_Var2 = &g_token_save_frame->on_pop;
      g_token_save_frame = *ppcVar1;
      if (*pp_Var2 != (_func_193 *)0x0) {
        (**pp_Var2)();
      }
    }
    g_compile_flags_c8 = g_compile_flags_c8 & 0x7fffffff;
  }
  g_compile_flags_cc = g_compile_flags_cc & 0xffffffdf;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfdffffff;
  tmpl_close_parameter_scope();
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)))) && ((g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    if ((g_compile_flags_cc & 1) == 0) {
      g_expr_arena_index = 5;
      g_context_arena_index = 5;
      return;
    }
    g_context_arena_index = 4;
    g_expr_arena_index = 4;
    return;
  }
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  return;
}

