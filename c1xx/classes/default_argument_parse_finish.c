void __fastcall default_argument_parse_finish(c1_deferred_parse *rec)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_node *pcVar3;
  c1xx_token_stream *token_stream;
  
  decl_state_restore(g_current_scope,rec->keep_state);
  decl_state_pop(g_current_scope);
  if (rec->keep_state == '\0') {
    pcVar3 = tree_copy_to_arena(rec->params->defaults,0);
    rec->params->defaults = pcVar3;
  }
  else {
    do {
      if (g_token_source == (c1_token_source_frame *)0x0) {
        token_stream = (c1xx_token_stream *)0x0;
      }
      else {
        token_stream = g_token_source->stream;
        ppcVar1 = &g_token_source->prev;
        g_token_position = g_token_source->position;
        pp_Var2 = &g_token_source->on_pop;
        g_token_source = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
        }
      }
    } while ((token_stream != rec->stream) &&
            ((*token_stream->vtbl->peek)(token_stream), token_stream != rec->stream));
  }
  if (rec->set_cc_10 != '\0') {
    g_compile_flags_cc = g_compile_flags_cc & 0xffffffef;
  }
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)))) && ((g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if ((g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      return;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  return;
}

