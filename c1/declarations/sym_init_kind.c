c1_symbol * __thiscall sym_init_kind(c1_symbol *sym,c1_u8 kind,void *name,int unused)

{
  fe_name **ppfVar1;
  
  sym->kind = (sym->kind ^ kind) & 0x1f ^ sym->kind;
  ppfVar1 = &sym->name;
  if (kind == '\x04') {
    if (ppfVar1 != (fe_name **)0x0) {
      sym->next = (c1_sym_link *)0x0;
      *ppfVar1 = name;
      sym->tag_members = (void *)0x0;
    }
  }
  else if (ppfVar1 != (fe_name **)0x0) {
    sym->next = (c1_sym_link *)0x0;
    *ppfVar1 = name;
    return sym;
  }
  return sym;
}

