char * __cdecl pch_and_pdb_names(void)

{
  char *pcVar1;
  
  if (g_pch_automatic != '\0') {
    pcVar1 = pch_default_name("vc60.pch");
    pcVar1 = pdb_relative_path(pcVar1);
    return pcVar1;
  }
  pcVar1 = g_create_pch_header_name;
  if (g_create_pch_header_name == (char *)0x0) {
    pcVar1 = g_opt_source_file;
  }
  pcVar1 = pch_default_name(pcVar1);
  pcVar1 = pdb_relative_path(pcVar1);
  return pcVar1;
}

