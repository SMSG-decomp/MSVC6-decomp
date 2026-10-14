void __fastcall asm_print_public(c2_fe_symbol *s)

{
  int iVar1;
  uint8_t *puVar2;
  
  if ((((s->flags31 & 4) != 0) && ((s->flags31 & 2) == 0)) &&
     (((s->cls == '\x04' && (((byte)s->storage & 0xf0) == 0x50)) ||
      ((s->cls == '\x01' && ((s->storage & 0x780) == 0x80)))))) {
    g_asm_current_segment = (c2_fe_symbol *)asm_print_segment_end(g_asm_current_segment);
    iVar1 = asm_printf("PUBLIC");
    g_asm_column = g_asm_column + iVar1;
    asm_pad_to_column(8);
    puVar2 = fe_symbol_external_name(s);
    iVar1 = asm_printf("%s",puVar2);
    g_asm_column = g_asm_column + iVar1;
    if (*s->name == '?') {
      asm_print_symbol_operand(s,1);
    }
    g_asm_column = 0;
    asm_printf(g_asm_newline);
  }
  return;
}

