void __cdecl opt_resolve_pch_switches(char *yc_header,char *yu_header,int zero)

{
  char cVar1;
  
  cVar1 = file_name_equal((byte *)yc_header,(byte *)yu_header);
  if (cVar1 != '\0') {
    g_use_pch = '\0';
    g_opt_Yu_header = zero;
  }
  if (g_pch_create == '\0') {
    g_opt_pch_types_in_pdb = 0;
  }
  if (g_opt_Yu_header != zero) {
    g_use_pch = '\x01';
  }
  if (g_opt_YX_header != zero) {
    g_pch_automatic = '\x01';
  }
  g_pch_debug_in_object = g_pch_debug_in_object | g_pch_automatic;
  if ((g_opt_E_preprocess != zero) || (g_opt_Zg != '\0')) {
    g_pch_automatic = '\0';
    g_pch_create = '\0';
    g_use_pch = '\0';
    g_pch_debug_in_object = '\0';
    g_opt_pch_types_in_pdb = 0;
    g_opt_Yu_header = zero;
    g_create_pch_header_name = (char *)zero;
    g_opt_YX_header = zero;
  }
  if (g_switch_words != (char **)zero) {
    mem_free(g_switch_words);
    g_switch_words = (char **)zero;
  }
  return;
}

