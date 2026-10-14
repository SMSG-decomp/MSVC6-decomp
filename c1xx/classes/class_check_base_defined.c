c1_symbol * __cdecl class_check_base_defined(int access,int is_virtual,fe_name *name,int unused)

{
  c1_lookup_entry *pcVar1;
  c1_symbol *pcVar2;
  
  pcVar1 = (c1_lookup_entry *)class_lookup_qualified_name(g_current_scope,name);
  if (pcVar1 == (c1_lookup_entry *)0x0) {
    pcVar1 = lookup_name_in_context(g_current_scope,name,0x132);
    if (pcVar1 == (c1_lookup_entry *)0x0) {
      diag_error(0x1f8,0x49,name);
      return (c1_symbol *)0x0;
    }
  }
  pcVar2 = class_check_base_class(access,(char)is_virtual,pcVar1->sym);
  return pcVar2;
}

