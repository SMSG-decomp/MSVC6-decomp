void __cdecl
access_record_inaccessible_via_base
          (c1_symbol *member,c1_symbol *cls,char inherit_access,char access,c1_symbol *base)

{
  g_access_report_class = cls;
  g_access_report_member = member;
  g_access_report_base = base;
  g_access_report_inherit_access = inherit_access;
  g_access_report_access = access;
  return;
}

