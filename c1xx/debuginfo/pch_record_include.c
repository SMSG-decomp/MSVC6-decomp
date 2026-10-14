int __cdecl pch_record_include(byte *file)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (g_pch_directive_mode == 1) {
    pragma_section_record(2,g_pch_header.include_key,(char *)file);
    g_pch_include_count.count = g_pch_include_count.count + -1;
    if (((g_pch_include_count.count != 0) && (g_opt_YX_header != (byte *)0x0)) &&
       (cVar1 = file_name_equal(g_opt_YX_header,file), cVar1 != '\0')) {
      g_pch_include_count.count = 0;
    }
    return 2;
  }
  if (g_pch_directive_mode == 2) {
    if ((*g_pch_record_cursor == 2) &&
       (cVar1 = file_name_equal((byte *)(g_pch_record_cursor + 3),file), cVar1 != '\0')) {
      g_pch_include_count.count = g_pch_include_count.count + 1;
      g_pch_include_count.last_key = (short)g_pch_record_cursor[2];
      g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
      if (*g_pch_record_cursor != 8) {
        return 2;
      }
      while ((uVar2 = file_mtime((char *)(g_pch_record_cursor + 3)), g_pch_record_cursor[2] == uVar2
             || (g_pch_file_time_changed = 1, g_pch_auto_never_recreate == 0))) {
        g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
        if (*g_pch_record_cursor != 8) {
          return 2;
        }
      }
    }
    iVar3 = pch_auto_match_end();
    return iVar3;
  }
  return 0;
}

