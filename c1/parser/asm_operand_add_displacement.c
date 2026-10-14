void __cdecl asm_operand_add_displacement(int value)

{
  c1_u8 *pcVar1;
  
  g_asm_operand->expr->disp = g_asm_operand->expr->disp + value;
  pcVar1 = &g_asm_operand->expr->kind;
  *pcVar1 = *pcVar1 | 2;
  return;
}

