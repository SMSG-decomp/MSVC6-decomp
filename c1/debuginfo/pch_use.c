void __cdecl pch_use(byte *header_name,char is_yu_header)

{
  c1_u8 cVar1;
  char cVar2;
  c1_token *pcVar3;
  int iVar4;
  byte *pbVar5;
  
  g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
  g_compile_flags_c8 = g_compile_flags_c8 | 0x40000;
  g_context_arena_index = 3;
  g_expr_arena_index = 3;
  if ((g_auto_pch_using == 0) || (is_yu_header == '\0')) {
    if (header_name != (byte *)0x0) goto LAB_1062c496;
  }
  else {
    if (header_name != (byte *)0x0) {
LAB_1062c496:
      do {
        if ((g_forced_include_files == (ushort *)0x0) ||
           ((int)(uint)*g_forced_include_files <= (int)(short)g_forced_include_index))
        goto joined_r0x1062c4f6;
        g_forced_include_current =
             *(byte **)(*(int *)(g_forced_include_files + 4) + (short)g_forced_include_index * 4);
        g_forced_include_index._0_2_ = (short)g_forced_include_index + 1;
        cVar2 = file_name_equal(header_name,g_forced_include_current);
      } while (cVar2 == '\0');
      if (is_yu_header != '\0') {
        pch_set_name((char *)header_name);
      }
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffbffff;
      goto joined_r0x1062c4f6;
    }
    g_compile_flags_cc = g_compile_flags_cc | 0x10000;
  }
  for (; (g_forced_include_files != (ushort *)0x0 &&
         ((int)(short)g_forced_include_index < (int)(uint)*g_forced_include_files));
      g_forced_include_index._0_2_ = (short)g_forced_include_index + 1) {
    g_forced_include_current =
         *(byte **)(*(int *)(g_forced_include_files + 4) + (short)g_forced_include_index * 4);
  }
joined_r0x1062c4f6:
  do {
    if ((g_compile_flags_c8 & 0x40000) == 0) {
      if (is_yu_header == '\0') {
        g_pch_file_name = (char *)0x0;
      }
      else {
        (*g_il_emitter->vtbl->flush)();
        pch_open();
        (*g_il_emitter->vtbl->flush)();
      }
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
      return;
    }
    if (header_name != (byte *)0x0) break;
    cVar1 = pp_skip_to_directive();
    while (cVar1 != '\b') {
      cVar1 = pp_skip_to_directive();
    }
    pcVar3 = token_next(&g_token_position);
    if ((pcVar3->code == '\x06') &&
       (iVar4 = pragma_lookup_name(((pcVar3->value).name)->text), iVar4 == 0x1d)) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
      pragma_hdrstop((char **)(-(uint)(is_yu_header != '\0') & 0x1065deec));
      pragma_expect_dash_token();
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
      pbVar5 = g_opt_source_file;
      goto joined_r0x1062c63b;
    }
    lex_skip_whitespace();
  } while( true );
  cVar1 = pp_skip_to_directive();
  while (cVar1 != '\a') {
    if (cVar1 == '\x06') {
      pp_define_parse('\0');
    }
    cVar1 = pp_skip_to_directive();
  }
  pbVar5 = (byte *)pp_include_parse_filename('\x01',(char *)0x0);
  cVar2 = file_name_equal(header_name,pbVar5);
  pbVar5 = header_name;
  if (cVar2 != '\0') {
joined_r0x1062c63b:
    if (is_yu_header != '\0') {
      pch_set_name((char *)pbVar5);
    }
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffbffff;
    g_compile_flags_cc = g_compile_flags_cc & 0xfffeffff;
  }
  goto joined_r0x1062c4f6;
}

