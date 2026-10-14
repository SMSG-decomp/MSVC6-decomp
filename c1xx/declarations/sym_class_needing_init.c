c1_symbol * __cdecl sym_class_needing_init(c1_symbol *sym)

{
  byte bVar1;
  c1_symbol *cls;
  
  if ((sym->flags2 & 0x10) != 0) {
    return (c1_symbol *)0x0;
  }
  if ((sym->storage & 7) == 7) {
    return (c1_symbol *)0x0;
  }
  cls = sym_class_type_of(sym);
  if (cls == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
  if ((cls->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(cls);
  }
  bVar1 = ((cls->detail).cls)->implicit_state41;
  if ((((bVar1 & 0x10) != 0) && ((bVar1 & 2) != 0)) && ((bVar1 & 8) != 0)) {
    return (c1_symbol *)(~-(uint)((((cls->detail).cls)->layout_flags3c & 1) != 0) & (uint)cls);
  }
  return cls;
}

