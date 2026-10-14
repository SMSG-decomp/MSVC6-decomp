c1_symbol * __thiscall decl_check_reference_initialized(byte type_code,c1_declarator *d)

{
  c1_symbol *pcVar1;
  
  if ((type_code & 0x8f) == 0x80) {
    pcVar1 = d->sym;
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = sym_new_from_declarator(d,5);
    }
    diag_error(0x212,pcVar1);
  }
  if ((d->sym->flags22 & 2) != 0) {
    pcVar1 = decl_based_variable_tail(d->sym,d);
    return pcVar1;
  }
  decl_assign_data_segment_and_check(d);
  g_file_scope_decl_since_body = 1;
  return d->sym;
}

