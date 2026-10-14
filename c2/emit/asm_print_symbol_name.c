void __fastcall asm_print_symbol_name(void *sym)

{
  uint8_t *fmt;
  int iVar1;
  
  if (sym != (void *)0x0) {
    fmt = fe_symbol_external_name(sym);
    iVar1 = asm_printf((char *)fmt);
    g_asm_column = g_asm_column + iVar1;
  }
  return;
}

