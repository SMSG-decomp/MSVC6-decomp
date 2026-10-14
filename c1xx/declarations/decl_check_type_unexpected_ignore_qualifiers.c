void decl_check_type_unexpected_ignore_qualifiers(c1_decl_spec_scan *state,uint code)

{
  diag_warning(1,((short)code != 0x81) + 0xb4);
  state->cv = 0;
  decl_check_qualifier_position(state->named_type,state);
  return;
}

