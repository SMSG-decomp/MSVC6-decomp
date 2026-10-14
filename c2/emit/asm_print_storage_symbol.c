void __fastcall asm_print_storage_symbol(c2_symbol *sym)

{
  c2_fe_symbol *s;
  uint8_t *fmt;
  int iVar1;
  
  if (sym != (c2_symbol *)0x0) {
    if (sym->storage != (c2_symbol *)0x0) {
      sym = sym->storage;
    }
    s = sym->fe;
    if (s != (c2_fe_symbol *)0x0) {
      if (s != (c2_fe_symbol *)0x0) {
        fmt = fe_symbol_external_name(s);
        iVar1 = asm_printf((char *)fmt);
        g_asm_column = g_asm_column + iVar1;
      }
      return;
    }
    iVar1 = asm_printf("%ld+",sym->offset);
    g_asm_column = g_asm_column + iVar1;
  }
  return;
}

