c1_symbol * __fastcall sym_ensure_declarator_symbol(c1_declarator *d)

{
  c1_symbol *pcVar1;
  
  pcVar1 = d->sym;
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = sym_new_from_declarator(d,5);
  }
  return pcVar1;
}

