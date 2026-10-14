void * __cdecl name_intern_decorated_in_scope_2(c1_symbol *sym2,c1_symbol *sym,char other_owner)

{
  char *s;
  void *pvVar1;
  
  if (other_owner == '\0') {
    sym->name = g_name_template_static_member_dtor;
  }
  else {
    sym->name = g_name_template_static_member_ctor;
  }
  sym->flags1 = sym->flags1 & 0xfc;
  s = decorate_name_swapped((int)sym2,sym);
  pvVar1 = name_intern(s);
  return pvVar1;
}

