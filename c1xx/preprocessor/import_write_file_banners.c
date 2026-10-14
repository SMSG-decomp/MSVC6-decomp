void __cdecl import_write_file_banners(int syskind)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char local_18 [12];
  char local_c [12];
  
  if (syskind == 0) {
    pcVar3 = "Win16 ";
  }
  else if (syskind == 1) {
    pcVar3 = "Win32 ";
  }
  else if (syskind == 2) {
    pcVar3 = "Macintosh ";
  }
  else {
    pcVar3 = "";
  }
  if (g_import_implementation_only == 0) {
    pcVar1 = _strtime(local_18);
    pcVar2 = _strdate(local_c);
    fprintf((FILE *)g_import_tlh_file,
            "%s\n//\n// %s\n//\n// C++ source equivalent of %stype library %s\n// compiler-generated file created %s at %s - DO NOT EDIT!\n"
            ,&g_import_banner,g_import_tlh_path,pcVar3,g_import_file_as_written,pcVar2,pcVar1);
    if ((g_import_tlh_file->_flag & 0x20) != 0) {
      diag_fatal_file_errno(0x55,0x154,g_import_tlh_path);
    }
  }
  if (g_import_no_implementation == 0) {
    pcVar1 = _strtime(local_18);
    pcVar2 = _strdate(local_c);
    fprintf((FILE *)g_import_tli_file,
            "%s\n//\n// %s\n//\n// Wrapper implementations for %stype library %s\n// compiler-generated file created %s at %s - DO NOT EDIT!\n\n"
            ,&g_import_banner,g_import_tli_path,pcVar3,g_import_file_as_written,pcVar2,pcVar1);
    if ((g_import_tli_file->_flag & 0x20) != 0) {
      diag_fatal_file_errno(0x55,0x154,g_import_tli_path);
    }
  }
  return;
}

