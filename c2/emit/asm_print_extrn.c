void __fastcall asm_print_extrn(c2_fe_symbol *s)

{
  uint8_t uVar1;
  int iVar2;
  uint8_t *puVar3;
  char *pcVar4;
  
  if ((((s->flags31 & 4) != 0) && ((s->flags31 & 2) == 0)) &&
     (((uVar1 = s->cls, uVar1 == '\x04' && (((byte)s->storage & 0xf0) == 0x40)) ||
      ((uVar1 == '\x01' && ((s->storage & 0x780) == 0x100)))))) {
    g_asm_current_segment = (c2_fe_symbol *)asm_print_segment_end(g_asm_current_segment);
    if (uVar1 == '\x04') {
      pcVar4 = "NEAR";
    }
    else {
      pcVar4 = asm_size_keyword(s->size);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = asm_size_keyword(1);
      }
    }
    iVar2 = asm_printf("EXTRN");
    g_asm_column = g_asm_column + iVar2;
    asm_pad_to_column(8);
    puVar3 = fe_symbol_external_name(s);
    iVar2 = asm_printf("%s:%s",puVar3,pcVar4);
    g_asm_column = g_asm_column + iVar2;
    if (*s->name == '?') {
      asm_print_symbol_operand(s,1);
    }
    g_asm_column = 0;
    asm_printf(g_asm_newline);
  }
  return;
}

