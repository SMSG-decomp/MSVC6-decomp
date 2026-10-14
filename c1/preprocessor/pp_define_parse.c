void __cdecl pp_define_parse(char notify_idb)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte *length;
  uint uVar4;
  uint uVar5;
  
  if (notify_idb != '\0') {
    (*g_idb->vtbl->idb_note_macro_change)(g_idb);
  }
  do {
    bVar3 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[bVar3] == '\x01');
  if ((g_char_flags[bVar3] & 0x20) == 0) {
    bVar3 = lex_skip_comment(bVar3);
  }
  if ((g_char_flags[bVar3] & 1) == 0) {
    diag_error(7);
    lex_skip_whitespace();
    return;
  }
  lex_scan_identifier(bVar3);
  g_define_formal_count = 0;
  bVar3 = *g_input_ptr;
  bVar1 = g_char_class[bVar3];
  g_define_text_ptr = g_macro_text_buffer;
  while( true ) {
    uVar5 = (uint)bVar3;
    g_input_ptr = g_input_ptr + 1;
    if (5 < bVar1) break;
    switch((&switchD_1060e329::switchdataD_1060e850)[bVar1]) {
    case (undefined *)0x1060e330:
      if (bVar3 != 0xd) goto code_r0x1060e335;
      break;
    case (undefined *)0x1060e395:
      pp_define_parse_formals();
      if (g_define_formal_count == 0) {
        g_define_formal_count = -1;
        pp_define_directive();
        return;
      }
      goto code_r0x1060e335;
    case (undefined *)0x1060e3af:
      g_input_ptr = g_input_ptr + -1;
      pp_define_finish((c1_u8 *)0x0,0,0);
      return;
    case (undefined *)0x10628ecf:
      uVar4 = lex_buffer_refill();
      if ((uVar4 & 0xffffffaf) == 0) goto switchD_1060e329_caseD_10628edf;
      break;
    case (undefined *)0x10628edf:
      goto switchD_1060e329_caseD_10628edf;
    case (undefined *)0x10628f19:
      if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
        bVar3 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 == 0x2f) {
          bVar3 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          if (g_char_class[bVar3] == '\0') {
            bVar3 = lex_next_significant_char(bVar3);
          }
          if (bVar3 != 0x2a) {
            g_input_ptr = g_input_ptr + -1;
            diag_warning(4,1);
            goto LAB_10628ffa;
          }
          diag_warning(4,0xb3);
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_skip_block_comment();
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_skip_comment();
          }
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        }
        else {
          bVar3 = g_input_ptr[-1];
          if (g_char_class[bVar3] == '\0') {
            bVar3 = lex_next_significant_char(bVar3);
          }
          if (bVar3 == 0x2a) {
LAB_106290f6:
            if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_skip_block_comment();
            }
            else {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_output_skip_comment();
            }
            goto LAB_1062900e;
          }
          g_input_ptr = g_input_ptr + -1;
        }
LAB_10628fa9:
        bVar2 = false;
      }
      else {
        bVar3 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 != 0x2f) {
          bVar3 = g_input_ptr[-1];
          if (g_char_class[bVar3] == '\0') {
            bVar3 = lex_next_significant_char(bVar3);
          }
          if (bVar3 == 0x2a) goto LAB_106290f6;
          g_input_ptr = g_input_ptr + -1;
          goto LAB_10628fa9;
        }
LAB_10628ffa:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
LAB_1062900e:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        bVar2 = true;
      }
      if (bVar2) {
code_r0x1060e335:
        length = pp_define_body();
        if (g_ms_extensions != '\0') {
          pp_define_finish(g_define_text_ptr,(uint)length,g_define_formal_count);
          return;
        }
        pp_define_finish(g_macro_text_buffer,
                         (uint)(length + ((int)g_define_text_ptr - (int)g_macro_text_buffer)),
                         g_define_formal_count);
        return;
      }
      uVar5 = 0x2f;
      goto LAB_10628ee6;
    }
    bVar3 = *g_input_ptr;
    bVar1 = g_char_class[bVar3];
  }
switchD_1060e329_caseD_10628edf:
LAB_10628ee6:
  diag_error(8,uVar5);
  pp_define_directive();
  return;
}

