void __thiscall type_check_based_form(c1_decl_record *rec,c1_decl_modifier *mod)

{
  if ((mod->bits & 8) != 0) {
    diag_error(0x1ed);
    rec->flags = rec->flags | 1;
  }
  rec->cc_bits = mod->bits;
  rec->based = mod->based;
  return;
}

