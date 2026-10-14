c1_u8 * __cdecl lex_scan_line_start_part(int one,c1_fputc_fn put_char)

{
  c1_u8 cVar1;
  byte bVar2;
  c1_u8 *pcVar3;
  c1_u8 *pcVar4;
  char cVar5;
  uint uVar6;
  c1_arena *pcVar7;
  c1_u8 *pcVar8;
  int iVar9;
  uint *puVar10;
  byte *pbVar11;
  uint *puVar12;
  
  cVar5 = lex_at_buffer_start();
  pbVar11 = g_input_ptr;
  if ((cVar5 != '\0') && (cVar5 = lex_begin_primary_file(), pbVar11 = g_input_ptr, cVar5 != '\0')) {
    do {
      g_input_ptr = g_input_ptr + 1;
      if ((g_opt_E_preprocess != 0) &&
         (((*put_char)(10,g_pp_output_stream), (g_compile_flags_c4 & 0x400000) != 0 &&
          (g_compile_flags_c4 = g_compile_flags_c4 & 0xffbfffff, g_opt_EP_no_line == '\0')))) {
        pp_emit_line_directive();
        (*put_char)(10,g_pp_output_stream);
      }
      g_lex_position = g_lex_position + 1;
      g_token_position = g_lex_position;
      if (g_include_depth != 0) goto LAB_10405f38;
      iVar9 = lex_line_number_of_position(&g_token_position);
      if (iVar9 != one) goto LAB_10405f38;
      cVar5 = lex_at_buffer_start();
      if (cVar5 == '\0') goto LAB_10405f38;
      cVar5 = lex_begin_primary_file();
      if (cVar5 == '\0') goto LAB_10405f38;
    } while( true );
  }
switchD_10405f62_caseD_1:
  g_input_ptr = pbVar11;
  if (g_opt_E_preprocess == 0) {
    cVar1 = g_char_class[*g_input_ptr];
    while (cVar1 == (c1_u8)one) {
      cVar1 = g_char_class[g_input_ptr[1]];
      g_input_ptr = g_input_ptr + 1;
    }
  }
  else if (g_input_ptr[-1] != 0xd) {
    (*put_char)((int)g_input_ptr[-1],g_pp_output_stream);
  }
LAB_10405f38:
  pbVar11 = g_input_ptr + 1;
  switch(g_char_class[*g_input_ptr]) {
  case '\0':
    bVar2 = *g_input_ptr;
    if ((bVar2 == 0) || (bVar2 == 0x1a)) {
      if (g_macro_expansion_depth == 0) {
        g_input_ptr = pbVar11;
        iVar9 = file_read_or_fatal();
        if (iVar9 != 0) {
          g_yylval = g_lex_position;
          if (g_token_arena_index == 0) {
            pcVar8 = pool_alloc_raw(&g_pool_default,0x30);
            pcVar8 = token_new_newline(pcVar8);
            return pcVar8;
          }
          pcVar8 = arena_alloc(g_arenas + g_token_arena_index,0x30);
          if (pcVar8 == (c1_u8 *)0x0) {
            return (c1_u8 *)0x0;
          }
          *pcVar8 = 0xf2;
          puVar10 = &g_yylval;
          puVar12 = (uint *)(pcVar8 + 8);
          for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          return pcVar8;
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
      uVar6 = lex_trigraph();
      uVar6 = uVar6 & 0xffffffbf;
    }
    else {
      g_input_ptr = pbVar11;
      uVar6 = lex_line_splice();
    }
    break;
  case '\x01':
    goto switchD_10405f62_caseD_1;
  default:
    goto switchD_10405f62_caseD_2;
  case '\x03':
    g_input_ptr = pbVar11;
    uVar6 = lex_skip_line_start_comment();
    break;
  case '\x05':
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    if ((g_include_depth == 0) &&
       (g_input_ptr = pbVar11, iVar9 = lex_line_number_of_position(&g_token_position),
       pbVar11 = g_input_ptr, iVar9 == one)) {
      pcVar8 = lex_scan_line_start_part(one,put_char);
      return pcVar8;
    }
    goto switchD_10405f62_caseD_1;
  case '\v':
    goto switchD_10405f62_caseD_b;
  }
  pbVar11 = g_input_ptr;
  if (uVar6 == 0) {
switchD_10405f62_caseD_2:
    g_input_ptr = pbVar11;
    g_input_ptr = g_input_ptr + -1;
    if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
      pcVar8 = lex_pch_stop_token();
      return pcVar8;
    }
    if ((g_compile_flags_c8 & 0x4000000) == 0) {
      if ((g_compile_flags_c4 & 0x200000) != 0) {
        g_yylval = g_lex_position;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          pcVar8 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar8 = token_new_newline(pcVar8);
          return pcVar8;
        }
        pcVar7 = g_arenas + g_token_arena_index;
        pcVar3 = pcVar7->cur;
        pcVar4 = g_arenas[g_token_arena_index].end;
        pcVar8 = pcVar3 + 0x30;
        pcVar7->cur = pcVar8;
        if (pcVar4 < pcVar8) {
          arena_grow(pcVar7);
        }
        pcVar8 = token_new_newline(pcVar3);
        return pcVar8;
      }
      if (((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) {
        il_emit_pragma_or_segment_record(0x24);
      }
    }
    else {
      g_yylval = g_lex_position;
      if (g_token_arena_index == 0) {
        pcVar8 = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        pcVar7 = g_arenas + g_token_arena_index;
        pcVar8 = pcVar7->cur;
        pcVar3 = g_arenas[g_token_arena_index].end;
        pcVar7->cur = pcVar8 + 0x30;
        if (pcVar3 < pcVar8 + 0x30) {
          arena_grow(pcVar7);
        }
      }
      if (pcVar8 != (c1_u8 *)0x0) {
        *pcVar8 = 0xf2;
        puVar10 = &g_yylval;
        puVar12 = (uint *)(pcVar8 + 8);
        for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        return pcVar8;
      }
    }
    return (c1_u8 *)0x0;
  }
  goto LAB_10405f38;
switchD_10405f62_caseD_b:
  g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
  g_input_ptr = pbVar11;
  pcVar8 = pp_directive();
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
  if (*pcVar8 != (c1_u8)one) {
    return pcVar8;
  }
  goto LAB_10405f38;
}

