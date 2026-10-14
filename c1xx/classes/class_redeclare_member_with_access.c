void __cdecl class_redeclare_member_with_access(int decl,int cls)

{
  c1_keyed_list *list;
  c1_symbol *sym;
  
  if ((decl != 0) && (cls != 0)) {
    list = class_lookup_member_name_thunk(*(c1_symbol **)(cls + 8),*(void **)(decl + 8),2);
    list->head->sym = (c1_symbol *)decl;
    sym = (c1_symbol *)sym_new_overload_set_record(list,*(fe_name **)(decl + 8),5);
    access_check_member(sym);
  }
  return;
}

