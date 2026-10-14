void __cdecl pch_use(char *header_name,char read_pch)

{
  char *name;
  char cVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = g_compile_flags_c4 | 0x8000;
  if (((g_compile_flags_c8 & 0x32000000) == 0) &&
     (((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
       ((g_compile_flags_c4 & 0x200) != 0)) && ((g_compile_flags_cc & 0x10) == 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if ((g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  g_compile_flags_c8 = g_compile_flags_c8 | 0x40000;
  g_compile_flags_c4 = uVar4;
  if ((g_auto_pch_using == 0) || (read_pch == '\0')) {
    if (header_name == (char *)0x0) goto LAB_10460d5e;
  }
  else if (header_name == (char *)0x0) {
    g_compile_flags_cc = g_compile_flags_cc | 0x10000;
LAB_10460d5e:
    for (; (g_forced_include_files != (ushort *)0x0 &&
           ((int)(short)g_forced_include_index < (int)(uint)*g_forced_include_files));
        g_forced_include_index._0_2_ = (short)g_forced_include_index + 1) {
      g_forced_include_current =
           *(byte **)(*(int *)(g_forced_include_files + 4) + (short)g_forced_include_index * 4);
    }
    goto joined_r0x10449781;
  }
  do {
    if ((g_forced_include_files == (ushort *)0x0) ||
       ((int)(uint)*g_forced_include_files <= (int)(short)g_forced_include_index))
    goto joined_r0x10449781;
    g_forced_include_current =
         *(byte **)(*(int *)(g_forced_include_files + 4) + (short)g_forced_include_index * 4);
    g_forced_include_index._0_2_ = (short)g_forced_include_index + 1;
    cVar1 = file_name_equal((byte *)header_name,g_forced_include_current);
  } while (cVar1 == '\0');
  if (read_pch != '\0') {
    pch_set_name(header_name);
  }
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfffbffff;
joined_r0x10449781:
  do {
    if ((g_compile_flags_c8 & 0x40000) == 0) {
      if (read_pch == '\0') {
        g_pch_file_name = (char *)0x0;
      }
      else {
        (*g_il_emitter->vtbl->flush)();
        pch_open();
        (*g_il_emitter->vtbl->flush)();
      }
      uVar4 = g_compile_flags_c4;
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
      if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
          ((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
           ((uVar4 & 0x200) != 0)))) &&
         (((g_compile_flags_cc & 0x10) == 0 && ((g_compile_flags_c8 & 0x4000000) == 0)))) {
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
    if (header_name != (char *)0x0) break;
    cVar1 = pp_skip_to_next_directive();
    while (cVar1 != '\b') {
      cVar1 = pp_skip_to_next_directive();
    }
    pbVar2 = token_next((c1_token_reader *)&g_token_position);
    if ((*pbVar2 == 6) &&
       (iVar3 = pragma_lookup_name(*(char **)(*(int *)(pbVar2 + 8) + 4)), iVar3 == 0x1d)) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
      pragma_hdrstop((char **)(-(uint)(read_pch != '\0') & 0x104d20a4));
      pragma_expect_dash_token();
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
      name = g_opt_source_file;
      goto joined_r0x10460e3a;
    }
    lex_skip_whitespace();
  } while( true );
  cVar1 = pp_skip_to_next_directive();
  while (cVar1 != '\a') {
    if (cVar1 == '\x06') {
      pp_define_parse(0);
    }
    cVar1 = pp_skip_to_next_directive();
  }
  pbVar2 = (byte *)pp_include_parse_filename('\x01',(char *)0x0);
  cVar1 = file_name_equal((byte *)header_name,pbVar2);
  name = header_name;
  if (cVar1 != '\0') {
joined_r0x10460e3a:
    if (read_pch != '\0') {
      pch_set_name(name);
    }
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffbffff;
    g_compile_flags_cc = g_compile_flags_cc & 0xfffeffff;
  }
  goto joined_r0x10449781;
}

