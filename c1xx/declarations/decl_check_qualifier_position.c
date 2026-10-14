void __fastcall decl_check_qualifier_position(c1_type *named_type,c1_decl_spec_scan *state)

{
  state->type = named_type;
  if ((state->cv & 0x300) != 0) {
    diag_error(0xdb);
  }
  return;
}

