c1_u8 * __cdecl lex_scan_line_start(void)

{
  c1_u8 cVar1;
  byte bVar2;
  c1_u8 *pcVar3;
  c1_u8 *pcVar4;
  code *put_char;
  char cVar5;
  int iVar6;
  uint uVar7;
  c1_arena *pcVar8;
  c1_u8 *pcVar9;
  uint *puVar10;
  byte *pbVar11;
  uint *puVar12;
  
  put_char = fputc_exref;
  while( true ) {
    if (((g_opt_E_preprocess != 0) &&
        (fputc(10,g_pp_output_stream), (g_compile_flags_c4 & 0x400000) != 0)) &&
       (g_compile_flags_c4 = g_compile_flags_c4 & 0xffbfffff, g_opt_EP_no_line == '\0')) {
      pp_emit_line_directive();
      fputc(10,g_pp_output_stream);
    }
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    if (((g_include_depth != 0) ||
        (iVar6 = lex_line_number_of_position(&g_token_position), iVar6 != 1)) ||
       ((cVar5 = lex_at_buffer_start(), cVar5 == '\0' ||
        (cVar5 = lex_begin_primary_file(), cVar5 == '\0')))) break;
    g_input_ptr = g_input_ptr + 1;
  }
LAB_10405f38:
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
            pcVar9 = pool_alloc_raw(&g_pool_default,0x30);
            pcVar9 = token_new_newline(pcVar9);
            return pcVar9;
          }
          pcVar9 = arena_alloc(g_arenas + g_token_arena_index,0x30);
          if (pcVar9 == (c1_u8 *)0x0) {
            return (c1_u8 *)0x0;
          }
          *pcVar9 = 0xf2;
          puVar10 = &g_yylval;
          puVar12 = (uint *)(pcVar9 + 8);
          for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          return pcVar9;
        }
      }
      else {
        g_input_ptr = pbVar11;
        lex_buffer_refill();
      }
      goto LAB_10405f38;
    }
    if (bVar2 == 0x3f) {
      g_input_ptr = pbVar11;
      uVar7 = lex_trigraph();
      uVar7 = uVar7 & 0xffffffbf;
    }
    else {
      g_input_ptr = pbVar11;
      uVar7 = lex_line_splice();
    }
    break;
  default:
    goto switchD_10405f62_caseD_2;
  case '\x03':
    g_input_ptr = pbVar11;
    uVar7 = lex_skip_line_start_comment();
    break;
  case '\x05':
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    if ((g_include_depth == 0) &&
       (g_input_ptr = pbVar11, iVar6 = lex_line_number_of_position(&g_token_position),
       pbVar11 = g_input_ptr, iVar6 == 1)) {
      pcVar9 = lex_scan_line_start_part(1,put_char);
      return pcVar9;
    }
  case '\x01':
    g_input_ptr = pbVar11;
    if (g_opt_E_preprocess == 0) {
      cVar1 = g_char_class[*g_input_ptr];
      while (cVar1 == '\x01') {
        cVar1 = g_char_class[g_input_ptr[1]];
        g_input_ptr = g_input_ptr + 1;
      }
    }
    else if (g_input_ptr[-1] != 0xd) {
      fputc((uint)g_input_ptr[-1],g_pp_output_stream);
    }
    goto LAB_10405f38;
  case '\v':
    goto switchD_10405f62_caseD_b;
  }
  pbVar11 = g_input_ptr;
  if (uVar7 == 0) {
switchD_10405f62_caseD_2:
    g_input_ptr = pbVar11;
    g_input_ptr = g_input_ptr + -1;
    if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
      pcVar9 = lex_pch_stop_token();
      return pcVar9;
    }
    if ((g_compile_flags_c8 & 0x4000000) == 0) {
      if ((g_compile_flags_c4 & 0x200000) != 0) {
        g_yylval = g_lex_position;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          pcVar9 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar9 = token_new_newline(pcVar9);
          return pcVar9;
        }
        pcVar8 = g_arenas + g_token_arena_index;
        pcVar3 = pcVar8->cur;
        pcVar4 = g_arenas[g_token_arena_index].end;
        pcVar9 = pcVar3 + 0x30;
        pcVar8->cur = pcVar9;
        if (pcVar4 < pcVar9) {
          arena_grow(pcVar8);
        }
        pcVar9 = token_new_newline(pcVar3);
        return pcVar9;
      }
      if (((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) {
        il_emit_pragma_or_segment_record(0x24);
      }
    }
    else {
      g_yylval = g_lex_position;
      if (g_token_arena_index == 0) {
        pcVar9 = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        pcVar8 = g_arenas + g_token_arena_index;
        pcVar9 = pcVar8->cur;
        pcVar3 = g_arenas[g_token_arena_index].end;
        pcVar8->cur = pcVar9 + 0x30;
        if (pcVar3 < pcVar9 + 0x30) {
          arena_grow(pcVar8);
        }
      }
      if (pcVar9 != (c1_u8 *)0x0) {
        *pcVar9 = 0xf2;
        puVar10 = &g_yylval;
        puVar12 = (uint *)(pcVar9 + 8);
        for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        return pcVar9;
      }
    }
    return (c1_u8 *)0x0;
  }
  goto LAB_10405f38;
switchD_10405f62_caseD_b:
  g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
  g_input_ptr = pbVar11;
  pcVar9 = pp_directive();
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
  if (*pcVar9 != '\x01') {
    return pcVar9;
  }
  goto LAB_10405f38;
}

