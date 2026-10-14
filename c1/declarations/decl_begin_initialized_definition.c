int __cdecl decl_begin_initialized_definition(c1_symbol *sym)

{
  byte bVar1;
  int extraout_EAX;
  
  if (g_opt_Zg != '\0') {
    return (int)sym;
  }
  if (sym == (c1_symbol *)0x0) {
    return 0;
  }
  if ((sym->flags2 & 1) != 0) {
    return (int)sym;
  }
  bVar1 = sym->storage & 7;
  if (bVar1 != 7) {
    if (bVar1 == 1) {
      if (g_block_depth != '\0') {
        diag_error(0xcd,sym);
      }
      sym->storage = sym->storage & 0xf8 ^ 2;
    }
    if ((sym->flags22 & 8) != 0) {
      g_compile_flags_cc = g_compile_flags_cc | 0x800;
    }
    init_begin_variable(sym);
    return extraout_EAX;
  }
  diag_error(0x47,sym);
  return 0;
}

