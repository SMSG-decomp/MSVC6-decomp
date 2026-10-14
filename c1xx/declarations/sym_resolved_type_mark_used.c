c1_type * __cdecl sym_resolved_type_mark_used(c1_symbol *sym)

{
  c1_type *pcVar1;
  
  if ((sym->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  if ((sym->kind & 0x1f) == 0x1a) {
    sym = *(c1_symbol **)sym->type;
  }
  pcVar1 = sym->type;
  if ((sym->kind & 0x1f) != 4) {
    sym_mark_referenced(sym);
    return pcVar1;
  }
  pcVar1 = sym_type_of(sym);
  return pcVar1;
}

