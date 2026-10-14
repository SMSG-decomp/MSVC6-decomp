void __cdecl cse_set_key_operands(uint32_t count,...)

{
  uint uVar1;
  c2_operand **ppcVar2;
  char *va_cursor;
  
  if (9 < count) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\hash.c",0x293);
  }
  uVar1 = 0;
  if (count != 0) {
    ppcVar2 = g_expr_operand_scratch;
    va_cursor = (char *)register0x00000010;
    do {
      if (*(c2_operand **)(va_cursor + 8) == (c2_operand *)0x0) break;
      *ppcVar2 = *(c2_operand **)(va_cursor + 8);
      uVar1 = uVar1 + 1;
      ppcVar2 = ppcVar2 + 1;
      va_cursor = va_cursor + 4;
    } while (uVar1 < count);
  }
  g_expr_operand_scratch[uVar1] = (c2_operand *)0x0;
  return;
}

