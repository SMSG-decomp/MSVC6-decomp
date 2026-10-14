void __fastcall type_check_reference_to_bitfield(c1_declarator *d)

{
  c1_symbol *pcVar1;
  
  if (d->kind == 1) {
    pcVar1 = d->sym;
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = sym_new_from_declarator(d,5);
    }
    diag_error(0x213,pcVar1);
  }
  return;
}

