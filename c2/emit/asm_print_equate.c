void __fastcall asm_print_equate(c2_fe_symbol *s)

{
  uint8_t *puVar1;
  int32_t iVar2;
  
  if (((s->flags31 & 4) != 0) && ((s->flags31 & 2) == 0)) {
    if ((s->cls == '\x01') &&
       ((((byte)s->storage & 0x70) == 0x10 || (((byte)s->storage & 0x70) == 0x30)))) {
      iVar2 = s->offset;
      puVar1 = fe_symbol_external_name(s);
      asm_printf("%s = %ld",puVar1,iVar2);
      g_asm_column = 0;
      asm_printf(g_asm_newline);
    }
    s->flags31 = s->flags31 | 2;
  }
  return;
}

