void __cdecl lex_begin_source_file(ushort *defines)

{
  char cVar1;
  char *pcVar2;
  int fd;
  uint uVar3;
  uint uVar4;
  short sVar5;
  char *pcVar6;
  uint local_4;
  
  builtin_memcpy(g_char_class + 1,"&\'()",4);
  if (g_ms_extensions != '\0') {
    g_char_class[0x24] = '\x06';
    g_char_flags[0x24] = g_char_flags[0x24] | 1;
  }
  if (g_opt_Brepro == 0) {
    pp_time_now(&local_4);
    pcVar2 = pp_format_date_time_strings(local_4);
    uVar3 = 0xffffffff;
    do {
      pcVar6 = pcVar2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar2 = pcVar6 + -uVar3;
    pcVar6 = g_pp_date_time_text;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar6 = pcVar6 + 1;
    }
    g_pp_date_text = g_pp_date_time_text + 4;
    g_pp_date_time_text[0xf] = '\0';
    g_pp_time_text = g_pp_date_time_text + 0x10;
    g_pp_date_time_text[0x18] = '\0';
  }
  else {
    g_pp_date_time_text[0] = '1';
    g_pp_date_time_text[1] = '\0';
    g_pp_date_text = g_pp_date_time_text;
    g_pp_time_text = g_pp_date_time_text;
  }
  lex_reset_buffers();
  name_intern("__LINE__");
  pp_define_finish((c1_u8 *)0x0,0,-4);
  name_intern("__FILE__");
  pp_define_finish((c1_u8 *)0x0,0,-5);
  name_intern("__DATE__");
  pp_define_finish((c1_u8 *)0x0,0,-6);
  name_intern("__TIME__");
  pp_define_finish((c1_u8 *)0x0,0,-7);
  name_intern("__TIMESTAMP__");
  pp_define_finish((c1_u8 *)0x0,0,-9);
  name_intern("__cplusplus");
  pp_define_finish((c1_u8 *)0x0,0,-10);
  if (g_opt_noBool == '\0') {
    name_intern("__BOOL_DEFINED");
    pp_define_finish((c1_u8 *)0x0,0,-0xb);
  }
  for (sVar5 = 0; (defines != (ushort *)0x0 && ((int)sVar5 < (int)(uint)*defines));
      sVar5 = sVar5 + 1) {
    pp_define_from_switch(*(byte **)(*(int *)(defines + 4) + sVar5 * 4));
  }
  if ((g_opt_E_preprocess == 0) && ((g_c9il_mode != '\0' && (g_opt_Zg == '\0')))) {
    il_globals_rewind();
  }
  fd = file_open_or_fatal(g_opt_source_file,0,1,1,0);
  if (-1 < fd) {
    if (g_auto_pch_creating == 0) {
      g_forced_include_index._0_2_ = 0;
      g_forced_include_files = g_forced_include_list;
      return;
    }
    pragma_section_attribute(g_opt_source_file,fd);
    g_forced_include_index._0_2_ = 0;
    g_forced_include_files = g_forced_include_list;
    return;
  }
  g_forced_include_index._0_2_ = 0;
  g_forced_include_files = g_forced_include_list;
  return;
}

