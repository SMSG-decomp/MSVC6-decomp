void __cdecl init_set_target_symbol(c1_symbol *sym)

{
  int iVar1;
  
  PTR_104d2c58 = sym;
  if ((sym != (c1_symbol *)0x0) && (iVar1 = sym_has_reference_type(sym), (char)iVar1 != '\0')) {
    g_init_target_is_reference = '\x01';
    return;
  }
  g_init_target_is_reference = '\0';
  return;
}

