c1_type * __cdecl sym_type_for_specifier(c1_symbol *sym)

{
  c1_type *pcVar1;
  
  pcVar1 = sym->type;
  if ((sym->kind & 0x1f) != 4) {
    sym_mark_referenced(sym);
    return pcVar1;
  }
  pcVar1 = sym_type_enum_as_int(sym);
  return pcVar1;
}

