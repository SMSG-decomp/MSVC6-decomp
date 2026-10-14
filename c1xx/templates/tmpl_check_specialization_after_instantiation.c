undefined4 tmpl_check_specialization_after_instantiation(uint ebx,c1_decl_spec_scan *state)

{
  c1_u8 *pcVar1;
  c1_u8 *unaff_EBP;
  
  diag_error(0x38c,0x53);
  if (*unaff_EBP != '\"') {
    if (*unaff_EBP != '#') {
      return 0;
    }
    g_compile_flags_c4 = g_compile_flags_c4 | ebx;
  }
  decl_check_type_unexpected((int)state);
  if ((state->spec[1] & 4) != 0) {
    diag_error(0x187,state->type_sym);
  }
  pcVar1 = decl_scan_make_specifier_token(state,*unaff_EBP);
  state->token = pcVar1;
  return 2;
}

