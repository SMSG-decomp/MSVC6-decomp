void __cdecl class_declare_copy_ctor_closure(c1_symbol *cls,c1_symbol *copy_ctor)

{
  c1_symbol *fn;
  c1_symtab *tab;
  byte bVar1;
  
  fn = class_declare_implicit_member(cls,8,'\x01','\0');
  if (((copy_ctor->flags22 & 0xc) != 0) && (bVar1 = fn->flags22, (bVar1 & 0xc) == 0)) {
    bVar1 = (bVar1 ^ copy_ctor->flags22) & 4 ^ bVar1;
    fn->flags22 = bVar1;
    bVar1 = (bVar1 ^ copy_ctor->flags22) & 8 ^ bVar1;
    fn->flags22 = bVar1;
    if ((bVar1 & 4) != 0) {
      special_member_need_definition(fn);
    }
  }
  tab = class_ensure_copy_ctor_closure_table();
  symtab_insert(tab,copy_ctor,fn);
  return;
}

