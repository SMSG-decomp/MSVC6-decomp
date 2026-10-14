c1_symbol * __thiscall sym_init_kind(c1_symbol *sym,c1_u8 kind,void *name,int unused)

{
  sym->kind = (sym->kind ^ kind) & 0x1f ^ sym->kind;
  if (kind == '\x04') {
    if (&sym->name != (fe_name **)0x0) {
      sym->next = (c1_symbol *)0x0;
      sym->name = name;
      (sym->x28).members = (c1_sym_list *)0x0;
    }
  }
  else if ((kind < 0x10) || (0x11 < kind)) {
    if (&sym->name != (fe_name **)0x0) {
      sym->next = (c1_symbol *)0x0;
      sym->name = name;
      return sym;
    }
  }
  else if (&sym->name != (fe_name **)0x0) {
    sym->next = (c1_symbol *)0x0;
    sym->name = name;
    sym->type = (c1_type *)0x0;
    return sym;
  }
  return sym;
}

