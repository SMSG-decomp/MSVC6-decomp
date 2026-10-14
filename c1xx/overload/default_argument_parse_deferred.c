void __cdecl default_argument_parse_deferred(c1_symbol *fn,int arg3,int scope_rec)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_deferred_parse *pcVar3;
  c1_u8 *rec;
  c1_node *pcVar4;
  c1xx_token_stream *token_stream;
  bool bVar5;
  
  rec = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x24;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (rec == (c1_u8 *)0x0) {
    g_default_argument_parse_stack = (c1_deferred_parse *)0x0;
  }
  else {
    g_default_argument_parse_stack =
         tmpl_instantiation_context_init
                   ((c1_deferred_parse *)rec,fn,(c1_type **)arg3,(c1_node *)scope_rec,
                    g_default_argument_parse_stack);
  }
  default_argument_parse_in_class(g_default_argument_parse_stack);
  pcVar3 = g_default_argument_parse_stack;
  bVar5 = g_default_argument_parse_stack != (c1_deferred_parse *)0x0;
  g_default_argument_parse_stack = g_default_argument_parse_stack->prev;
  if (bVar5) {
    decl_state_restore(g_current_scope,pcVar3->keep_state);
    decl_state_pop(g_current_scope);
    if (pcVar3->keep_state == '\0') {
      pcVar4 = tree_copy_to_arena(pcVar3->params->defaults,0);
      pcVar3->params->defaults = pcVar4;
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
      } while ((token_stream != pcVar3->stream) &&
              ((*token_stream->vtbl->peek)(token_stream), token_stream != pcVar3->stream));
    }
    if (pcVar3->set_cc_10 != '\0') {
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
  return;
}

