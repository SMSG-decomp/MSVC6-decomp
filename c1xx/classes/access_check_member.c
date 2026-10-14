void __cdecl access_check_member(c1_symbol *sym)

{
  char cVar1;
  char *pcVar2;
  c1_symbol *pcVar3;
  int n;
  c1_symbol *pcVar4;
  
  if ((sym != (c1_symbol *)0x0) && ((g_compile_flags_cc & 0x300000) == 0)) {
    cVar1 = access_check_member_path(sym);
    if (cVar1 == '\0') {
      pcVar2 = access_entity_kind_text(g_access_report_member);
      if (g_access_report_class == (c1_symbol *)0x0) {
        if (((byte)g_compile_flags_c8 & 1) != 0) {
          diag_warning(3,0xf1,g_access_report_member);
          return;
        }
        diag_error(0xf1,g_access_report_member);
        return;
      }
      pcVar3 = (c1_symbol *)access_specifier_name(g_access_report_access);
      if (g_access_report_base == (c1_symbol *)0x0) {
        n = (g_access_report_via_virtual_base != 0) + 0xf8;
        pcVar4 = g_access_report_class;
      }
      else {
        pcVar2 = access_specifier_name(g_access_report_inherit_access);
        n = 0xf7;
        pcVar3 = g_access_report_class;
        pcVar4 = g_access_report_base;
      }
      if (((byte)g_compile_flags_c8 & 1) != 0) {
        diag_warning(3,n);
        return;
      }
      diag_error((short)n,g_access_report_member,pcVar3,pcVar2,pcVar4);
      return;
    }
  }
  return;
}

