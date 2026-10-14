void asm_print_symbol_directives(void)

{
  if (g_listing_on == 0) {
    return;
  }
  scope_for_each(0,asm_print_public);
  scope_for_each(0,asm_print_extrn);
  scope_for_each(1,asm_print_extrn);
  scope_for_each(0,asm_print_data_symbol_directive);
  scope_for_each(1,asm_print_data_symbol_directive);
  scope_for_each(0,asm_mark_symbol_listed);
  return;
}

