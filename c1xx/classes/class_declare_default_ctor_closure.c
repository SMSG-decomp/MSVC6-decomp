void __cdecl class_declare_default_ctor_closure(c1_symbol *cls,c1_symbol *ctor)

{
  c1_symbol *fn;
  c1_symtab *tab;
  byte bVar1;
  
  fn = class_declare_implicit_member(cls,10,'\x01','\0');
  if (((ctor->flags22 & 0xc) != 0) && (bVar1 = fn->flags22, (bVar1 & 0xc) == 0)) {
    bVar1 = (bVar1 ^ ctor->flags22) & 4 ^ bVar1;
    fn->flags22 = bVar1;
    bVar1 = (bVar1 ^ ctor->flags22) & 8 ^ bVar1;
    fn->flags22 = bVar1;
    if ((bVar1 & 4) != 0) {
      special_member_need_definition(fn);
    }
  }
  tab = symtab_ensure_16f4();
  symtab_insert(tab,ctor,fn);
  return;
}

