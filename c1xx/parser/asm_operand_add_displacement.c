void __cdecl asm_operand_add_displacement(int value)

{
  c1_u8 *pcVar1;
  
  g_asm_current_operand->record->value = g_asm_current_operand->record->value + value;
  pcVar1 = &g_asm_current_operand->record->kind;
  *pcVar1 = *pcVar1 | 2;
  return;
}

