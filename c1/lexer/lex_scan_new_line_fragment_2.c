c1_u8 * __cdecl lex_scan_new_line_fragment_2(uint flags_c4,int first_line,c1_fputc_fn put_char)

{
  c1_u8 cVar1;
  byte bVar2;
  c1_token *token;
  c1_token *pcVar3;
  uchar *token_00;
  bool bVar4;
  char cVar5;
  int iVar6;
  c1_u8 *pcVar7;
  uint uVar8;
  fe_arena *a;
  c1_token *pcVar9;
  uint *puVar10;
  byte *pbVar11;
  uint *puVar12;
  
  g_compile_flags_c4 = flags_c4 & 0xffbfffff;
  if (g_opt_EP_no_line == '\0') {
    pp_emit_line_directive();
    (*put_char)(10,g_pp_output_stream);
  }
  while ((((g_lex_position = g_lex_position + 1, g_token_position = g_lex_position,
           g_include_depth == 0 &&
           (iVar6 = lex_line_number_of_position(&g_token_position), iVar6 == first_line)) &&
          (bVar4 = lex_input_at_end(), bVar4)) && (cVar5 = lex_try_forced_include(), cVar5 != '\0'))
        ) {
    g_input_ptr = g_input_ptr + 1;
    if ((g_opt_E_preprocess != 0) &&
       ((*put_char)(10,g_pp_output_stream), (g_compile_flags_c4 & 0x400000) != 0)) {
      pcVar7 = lex_scan_new_line_fragment_2(g_compile_flags_c4,first_line,put_char);
      return pcVar7;
    }
  }
LAB_10603a13:
  pbVar11 = g_input_ptr + 1;
  switch(g_char_class[*g_input_ptr]) {
  case '\0':
    bVar2 = *g_input_ptr;
    if ((bVar2 == 0) || (bVar2 == 0x1a)) {
      if (g_macro_expansion_depth == 0) {
        g_input_ptr = pbVar11;
        iVar6 = file_read_or_fatal();
        if (iVar6 != 0) {
          g_yylval = g_lex_position;
          if (g_token_arena_index == 0) {
            pcVar9 = (c1_token *)pool_alloc_raw(&g_pool_default,0x20);
            pcVar9 = lex_scan_new_line_fragment(pcVar9);
            return &pcVar9->code;
          }
          pcVar7 = arena_alloc(g_arenas + g_token_arena_index,0x20);
          if (pcVar7 == (c1_u8 *)0x0) {
            return (c1_u8 *)0x0;
          }
          *pcVar7 = 0xf2;
          puVar10 = &g_yylval;
          puVar12 = (uint *)(pcVar7 + 8);
          for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          return pcVar7;
        }
      }
      else {
        g_input_ptr = pbVar11;
        lex_buffer_refill();
      }
      goto LAB_10603a13;
    }
    if (bVar2 == 0x3f) {
      g_input_ptr = pbVar11;
      uVar8 = lex_trigraph();
      uVar8 = uVar8 & 0xffffffbf;
    }
    else {
      g_input_ptr = pbVar11;
      uVar8 = lex_line_splice();
    }
    break;
  default:
    goto switchD_10603a3d_caseD_2;
  case '\x03':
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
      g_input_ptr = pbVar11;
      uVar8 = lex_skip_comment_in_directive();
    }
    else {
      g_input_ptr = pbVar11;
      uVar8 = lex_skip_line_start_comment();
    }
    break;
  case '\x05':
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    if ((g_include_depth == 0) &&
       (g_input_ptr = pbVar11, iVar6 = lex_line_number_of_position(&g_token_position),
       pbVar11 = g_input_ptr, iVar6 == first_line)) {
      pcVar7 = lex_scan_new_line_fragment_4(first_line,put_char);
      return pcVar7;
    }
  case '\x01':
    g_input_ptr = pbVar11;
    if (g_opt_E_preprocess == 0) {
      cVar1 = g_char_class[*g_input_ptr];
      while (cVar1 == (c1_u8)first_line) {
        cVar1 = g_char_class[g_input_ptr[1]];
        g_input_ptr = g_input_ptr + 1;
      }
    }
    else if (g_input_ptr[-1] != 0xd) {
      (*put_char)((int)g_input_ptr[-1],g_pp_output_stream);
    }
    goto LAB_10603a13;
  case '\v':
    goto switchD_10603a3d_caseD_b;
  }
  pbVar11 = g_input_ptr;
  if (uVar8 == 0) {
switchD_10603a3d_caseD_2:
    g_input_ptr = pbVar11;
    g_input_ptr = g_input_ptr + -1;
    if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
      pcVar7 = lex_scan_new_line_fragment_3();
      return pcVar7;
    }
    if ((g_compile_flags_c4 & 0x200000) == 0) {
      if (((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) {
        il_emit_pragma_or_segment_record(0x24);
      }
      return (c1_u8 *)0x0;
    }
    g_yylval = g_lex_position;
    if (g_token_arena_index == 0) {
      if (g_pool_default.left < 0x20) {
        pool_reserve(&g_pool_default,0x20);
      }
      token_00 = g_pool_default.cur;
      g_pool_default.cur = g_pool_default.cur + 0x20;
      g_pool_default.left = g_pool_default.left - 0x20;
      pcVar9 = lex_scan_new_line_fragment((c1_token *)token_00);
      return &pcVar9->code;
    }
    a = g_arenas + g_token_arena_index;
    token = (c1_token *)a->cur;
    pcVar3 = (c1_token *)g_arenas[g_token_arena_index].end;
    pcVar9 = token + 1;
    a->cur = &pcVar9->code;
    if (pcVar3 < pcVar9) {
      arena_grow(a);
    }
    pcVar9 = lex_scan_new_line_fragment(token);
    return &pcVar9->code;
  }
  goto LAB_10603a13;
switchD_10603a3d_caseD_b:
  g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
  g_input_ptr = pbVar11;
  pcVar7 = pp_scan_directive();
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
  if (*pcVar7 != (c1_u8)first_line) {
    return pcVar7;
  }
  goto LAB_10603a13;
}

