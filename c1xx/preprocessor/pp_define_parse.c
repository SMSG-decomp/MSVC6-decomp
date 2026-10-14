void __cdecl pp_define_parse(uint from_directive)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  c1_class_def_entry *pcVar5;
  int iVar6;
  
  if (((((char)from_directive != '\0') &&
       ((*g_idb->vtbl->idb_note_macro_change)(g_idb), g_minimal_rebuild != '\0')) &&
      (g_minimal_rebuild_tracker->current->tracked != '\0')) && (-1 < g_class_depth)) {
    pcVar5 = g_class_def_stack + g_class_depth;
    iVar6 = g_class_depth + 1;
    do {
      mre_note_class_records(g_minimal_rebuild_tracker,pcVar5->cls);
      pcVar5 = pcVar5 + -1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  do {
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[bVar2] == '\x01');
  if ((g_char_flags[bVar2] & 0x20) == 0) {
    bVar2 = lex_skip_comment(bVar2);
  }
  if ((g_char_flags[bVar2] & 1) == 0) {
    diag_error(7);
    lex_skip_whitespace();
    return;
  }
  lex_scan_identifier(bVar2);
  g_define_formal_count = 0;
  bVar2 = *g_input_ptr;
  bVar1 = g_char_class[bVar2];
  g_define_text_ptr = g_macro_text_buffer;
  while( true ) {
    uVar3 = (uint)bVar2;
    g_input_ptr = g_input_ptr + 1;
    if (5 < bVar1) break;
    switch((&switchD_104338a0::switchdataD_10437810)[bVar1]) {
    case (undefined *)0x104338a7:
      if (bVar2 != 0xd) goto code_r0x104338ac;
      break;
    case (undefined *)0x1043390c:
      pp_define_parse_formals();
      if (g_define_formal_count == 0) {
        g_define_formal_count = -1;
        pp_define_directive();
        return;
      }
code_r0x104338ac:
      uVar3 = pp_define_body();
      if (g_ms_extensions != '\0') {
        pp_define_finish(g_define_text_ptr,uVar3,g_define_formal_count);
        return;
      }
      pp_define_finish(g_macro_text_buffer,
                       (uint)(g_define_text_ptr + (uVar3 - (int)g_macro_text_buffer)),
                       g_define_formal_count);
      return;
    case (undefined *)0x10433926:
      g_input_ptr = g_input_ptr + -1;
      pp_define_finish((c1_u8 *)0x0,0,0);
      return;
    case (undefined *)0x1045c8fe:
      uVar4 = lex_buffer_refill();
      if ((uVar4 & 0xffffffaf) == 0) goto switchD_104338a0_caseD_2;
      break;
    case (undefined *)0x1045c90e:
      goto switchD_104338a0_caseD_2;
    case (undefined *)0x1045c948:
      bVar2 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 == 0x2f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        pp_define_directive();
        return;
      }
      bVar2 = g_input_ptr[-1];
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 == 0x2a) {
        if ((g_opt_C_keep_comments != 0) && ((g_compile_flags_c4 & 0x8000) == 0)) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_skip_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
          pp_define_directive();
          return;
        }
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_skip_block_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        pp_define_directive();
        return;
      }
      uVar3 = 0x2f;
      g_input_ptr = g_input_ptr + -1;
      goto LAB_1045c915;
    }
    bVar2 = *g_input_ptr;
    bVar1 = g_char_class[bVar2];
  }
switchD_104338a0_caseD_2:
LAB_1045c915:
  diag_error(8,uVar3);
  pp_define_directive();
  return;
}

