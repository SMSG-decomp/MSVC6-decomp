void __cdecl class_declare_local_vftable_ctor_closure(c1_symbol *cls,c1_symbol *ctor)

{
  c1_symbol *value;
  c1_symtab *tab;
  
  value = class_declare_implicit_member(cls,9,'\x01','\0');
  tab = symtab_ensure_16f8();
  symtab_insert(tab,ctor,value);
  return;
}

