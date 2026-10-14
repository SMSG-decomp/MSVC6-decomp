int __cdecl pragma_start_map_region(void)

{
  uchar *puVar1;
  c1_u8 *pcVar2;
  char local_104 [260];
  
  if ((g_compile_flags_cc & 0x800000) != 0) {
    diag_warning(1,0xc2);
  }
  puVar1 = pragma_warn_expected_token('v');
  if (puVar1 != (uchar *)0x0) {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x2000;
    pcVar2 = pragma_string_argument();
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
    if (*pcVar2 == '\a') {
      file_make_canonical_path(local_104,*(char **)(pcVar2 + 8),0x104);
      g_map_region_name = name_intern(local_104);
      pragma_warn_expected_token('~');
      g_compile_flags_cc = g_compile_flags_cc | 0x800000;
    }
  }
  return 0;
}

