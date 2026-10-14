void __fastcall decl_specifier_set_type_name(c1_specifier_state *spec)

{
  c1_symbol *sym;
  c1_type *pcVar1;
  
  sym = (spec->token->value).sym;
  (spec->named).sym = sym;
  pcVar1 = sym_type_for_specifier(sym);
  spec->named_type = pcVar1;
  return;
}

