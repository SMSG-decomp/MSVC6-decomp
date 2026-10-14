int __thiscall
decl_resolve_declarator_type_fragment
          (int level,c1_type *old_type,c1_type *new_type,c1_declarator *d,c1_symbol *sym)

{
  int iVar1;
  
  iVar1 = decl_compare_type_level(level,old_type,new_type,d,sym,sym);
  return iVar1;
}

