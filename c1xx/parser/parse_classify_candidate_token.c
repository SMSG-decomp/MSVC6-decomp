c1_u8 * __cdecl parse_classify_candidate_token(char allow_decl)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  int iVar3;
  byte bVar4;
  c1xx_token_stream *pcVar5;
  byte *pbVar6;
  char *pcVar7;
  uint uVar8;
  c1xx_token *token;
  c1_u8 *pcVar9;
  int iVar10;
  c1_type *type;
  uint *dst;
  c1xx_decl_specifiers *pcVar11;
  
  g_parse_block_record_depth = g_parse_block_record_depth + 1;
  if ((g_paren_level_flags[g_paren_depth] & 2) == 0) {
    pcVar5 = arena_alloc(g_arenas + 5,0x38);
    if (pcVar5 == (c1xx_token_stream *)0x0) {
      pcVar5 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar5 = token_stream_copy(pcVar5,g_token_source->stream);
    }
    token_source_push((c1_token_reader *)&g_token_position,pcVar5,5,0,(void *)0x0,&g_token_position)
    ;
    pbVar6 = token_next((c1_token_reader *)&g_token_position);
    type = *(c1_type **)(pbVar6 + 0x20);
    pcVar7 = parse_resolve_candidate_token_if_flagged((char *)pbVar6);
    iVar10 = g_paren_depth;
    iVar3 = g_sizeof_depth;
    if (pcVar7 != (char *)0x0) {
      if (g_token_source != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_source->prev;
        g_token_position = g_token_source->position;
        pp_Var2 = &g_token_source->on_pop;
        g_token_source = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
        }
      }
      pbVar6 = token_next((c1_token_reader *)&g_token_position);
      g_parse_block_record_depth = g_parse_block_record_depth + -1;
      return pbVar6;
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar6);
    if (g_parse_block_record_depth == 1) {
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfb;
    }
    uVar8 = parse_run_lookahead_classifier();
    g_sizeof_depth = iVar3;
    g_paren_depth = iVar10;
    if (g_token_source != (c1_token_source_frame *)0x0) {
      ppcVar1 = &g_token_source->prev;
      g_token_position = g_token_source->position;
      pp_Var2 = &g_token_source->on_pop;
      g_token_source = *ppcVar1;
      if (*pp_Var2 != (_func_193 *)0x0) {
        (**pp_Var2)();
      }
    }
    token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    switch(uVar8) {
    case 0:
      break;
    case 1:
      if ((((g_paren_depth < 1) ||
           (bVar4 = parse_no_saved_declspecs_below(g_paren_depth), bVar4 != 0)) &&
          (allow_decl != '\0')) && (g_sizeof_depth < 1)) goto switchD_1042f3a8_caseD_2;
      break;
    default:
      goto switchD_1042f3a8_caseD_2;
    case 3:
switchD_1042f3a8_caseD_3:
      parse_resolve_candidate_token((char *)token);
      goto switchD_1042f3a8_caseD_2;
    case 5:
      if ((((byte)g_compile_flags_c8 & 0x10) == 0) || (g_paren_depth != 0))
      goto switchD_1042f3a8_caseD_3;
    }
  }
  else {
    token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    type = token->type_value;
    pcVar9 = (c1_u8 *)parse_resolve_candidate_token_if_flagged((char *)token);
    if (pcVar9 != (c1_u8 *)0x0) {
      pcVar9 = parse_classify_candidate_token_exit(pcVar9);
      return pcVar9;
    }
  }
  tree_new_type_token_node(token,type);
switchD_1042f3a8_caseD_2:
  iVar3 = g_paren_depth;
  g_compile_flags_c4 = g_compile_flags_c4 | 0x40000000;
  if (token->code != 0x24) {
    if (token->code != 0xd9) {
      parse_scan_parenthesized_candidates();
    }
    g_parse_block_record_depth = g_parse_block_record_depth + -1;
    return &token->code;
  }
  dst = (uint *)&token->value;
  pcVar11 = g_paren_level_declspecs + g_paren_depth;
  for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(uint *)pcVar11->spec = *dst;
    dst = dst + 1;
    pcVar11 = (c1xx_decl_specifiers *)(pcVar11->spec + 4);
  }
  g_paren_level_flags[iVar3] = g_paren_level_flags[iVar3] | 1;
  g_parse_block_record_depth = g_parse_block_record_depth + -1;
  return &token->code;
}

