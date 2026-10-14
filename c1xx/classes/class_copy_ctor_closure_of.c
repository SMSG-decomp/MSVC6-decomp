c1_symbol * __cdecl class_copy_ctor_closure_of(c1_symbol *copy_ctor)

{
  c1_symtab *tab;
  c1_symbol *pcVar1;
  
  if (copy_ctor == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
  if ((copy_ctor->flags1 & 0x10) != 0x10) {
    return (c1_symbol *)0x0;
  }
  if ((*(byte *)((int)&copy_ctor->tail + 8) & 0x20) == 0) {
    return (c1_symbol *)0x0;
  }
  tab = class_ensure_copy_ctor_closure_table();
  pcVar1 = symtab_lookup(tab,copy_ctor);
  return pcVar1;
}

