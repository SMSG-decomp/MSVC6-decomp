void __fastcall decl_warn_modifiers_on_data(c1_decl_record *rec)

{
  if ((short)rec->cc_bits != 0) {
    diag_warning(1,0xe5);
    rec->cc_bits = 0;
    rec->based = (void *)0x0;
  }
  return;
}

