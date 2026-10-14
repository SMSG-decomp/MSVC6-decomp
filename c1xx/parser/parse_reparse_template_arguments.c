c1_arg_list * __cdecl parse_reparse_template_arguments(void *substream)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  byte bVar3;
  c1_symbol *pcVar4;
  int iVar5;
  c1_scope_stack *pcVar6;
  c1_arg_list *pcVar7;
  c1xx_token_stream *pcVar8;
  int iVar9;
  byte *tok;
  c1_u8 *local_c [2];
  c1_u8 local_4;
  c1_u8 local_3;
  c1_u8 local_2;
  
  parse_context_push(local_c);
  pcVar6 = g_current_scope;
  local_4 = g_current_scope->access_op;
  local_3 = g_current_scope->qualified;
  pcVar4 = g_current_scope->qual_class;
  local_2 = g_current_scope->reported;
  g_current_scope->reported = '\0';
  pcVar6->qual_class = (c1_symbol *)0x0;
  pcVar6->access_op = '\x01';
  pcVar6->qualified = '\0';
  pcVar8 = arena_alloc(g_arenas + 5,0x38);
  if (pcVar8 == (c1xx_token_stream *)0x0) {
    pcVar8 = (c1xx_token_stream *)0x0;
  }
  else {
    pcVar8 = token_stream_init(pcVar8,5,0);
  }
  token_source_push((c1_token_reader *)&g_token_record_position,pcVar8,5,0,(void *)0x0,
                    &g_token_position);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)g_token_template_args)
  ;
  if (substream != (void *)0x0) {
    tok = arena_alloc(g_arenas + 5,0x30);
    if (tok == (byte *)0x0) {
      tok = (byte *)0x0;
    }
    else {
      *tok = 0xf3;
      *(void **)(tok + 8) = substream;
    }
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)tok);
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)g_token_greater);
  }
  if (g_token_save_frame == (c1_token_source_frame *)0x0) {
    pcVar8 = (c1xx_token_stream *)0x0;
  }
  else {
    ppcVar1 = &g_token_save_frame->prev;
    pcVar8 = g_token_save_frame->stream;
    g_token_record_position = g_token_save_frame->position;
    pp_Var2 = &g_token_save_frame->on_pop;
    g_token_save_frame = *ppcVar1;
    if (*pp_Var2 != (_func_193 *)0x0) {
      (**pp_Var2)();
    }
  }
  token_source_push((c1_token_reader *)&g_token_position,pcVar8,5,1,(void *)0x0,&g_token_position);
  pcVar8 = g_token_source->stream;
  if ((pcVar8->flags & 2) == 0) {
    pcVar8->flags = pcVar8->flags | 2;
    (*pcVar8->vtbl->append)(pcVar8,g_token_end_of_stream);
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfff7fff8;
  g_context_arena_index = 0;
  bVar3 = g_paren_level_flags[g_paren_depth];
  g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
  g_paren_level_flags[g_paren_depth] = bVar3 & 0xfc;
  g_expr_arena_index = 0;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffff | 0x20000000;
  iVar9 = g_paren_depth + 1;
  if (0x3b < iVar9) {
    g_paren_depth = iVar9;
    diag_fatal_simple(0xd);
  }
  iVar5 = g_paren_depth + 1;
  g_paren_depth = iVar9;
  g_paren_level_flags[iVar5] = 0;
  g_paren_level_flags[iVar5] = 0x3c;
  iVar9 = parse_translation_unit();
  pcVar7 = g_reparsed_template_args;
  if (iVar9 == 0) {
    g_reparsed_template_args = (c1_arg_list *)0x0;
    if (local_3 == '\0') {
      g_current_scope->qual_class = (c1_symbol *)0x0;
      g_current_scope->access_op = '\x01';
      g_current_scope->qualified = '\0';
      g_current_scope->reported = '\0';
    }
    else {
      g_current_scope->qual_class = pcVar4;
      g_current_scope->access_op = local_4;
      g_current_scope->qualified = '\x01';
      g_current_scope->reported = local_2;
    }
    func_parse_state_pop(local_c);
    return pcVar7;
  }
  if (local_3 == '\0') {
    g_current_scope->qual_class = (c1_symbol *)0x0;
    g_current_scope->access_op = '\x01';
    g_current_scope->qualified = '\0';
    g_current_scope->reported = '\0';
    func_parse_state_pop(local_c);
    return (c1_arg_list *)0x0;
  }
  g_current_scope->qual_class = pcVar4;
  g_current_scope->access_op = local_4;
  g_current_scope->qualified = '\x01';
  g_current_scope->reported = local_2;
  func_parse_state_pop(local_c);
  return (c1_arg_list *)0x0;
}

