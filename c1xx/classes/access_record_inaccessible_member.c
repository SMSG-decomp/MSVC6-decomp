void __cdecl access_record_inaccessible_member(char access,c1_symbol *member,c1_symbol *cls)

{
  g_access_report_class = cls;
  g_access_report_member = member;
  g_access_report_access = access;
  return;
}

