c1_u8 * __cdecl asm_check_operand_type(c1_u8 *operand)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  byte bVar3;
  
  if ((((g_asm_operand->expr->kind & 1) == 0) ||
      (pcVar2 = g_asm_operand->expr->sym, pcVar2 == (c1_symbol *)0x0)) ||
     ((bVar3 = pcVar2->storage & 7, 3 < bVar3 && (bVar3 < 7)))) {
    diag_error(0x19f);
    g_asm_operand->expr->sym = g_builtin_label_1;
  }
  pcVar1 = &g_asm_operand->expr->kind;
  *pcVar1 = *pcVar1 & 0xe0;
  pcVar1 = &g_asm_operand->expr->kind;
  *pcVar1 = *pcVar1 | 0xb;
  g_asm_operand->size_class = '\x01';
  return operand;
}

