c1_symbol * __fastcall decl_symbol_or_new(c1_declaration *decl)

{
  c1_symbol *pcVar1;
  
  pcVar1 = decl->sym;
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = sym_new_from_declarator(decl,3);
  }
  return pcVar1;
}

