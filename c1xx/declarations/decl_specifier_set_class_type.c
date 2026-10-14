void __fastcall decl_specifier_set_class_type(int *state)

{
  c1_symbol *sym;
  c1_type *pcVar1;
  
  sym = *(c1_symbol **)(*state + 8);
  state[0xd] = (int)sym;
  pcVar1 = sym_resolved_type_mark_used(sym);
  state[0xc] = (int)pcVar1;
  *(byte *)(state + 5) = *(byte *)(state + 5) | 0x80;
  return;
}

