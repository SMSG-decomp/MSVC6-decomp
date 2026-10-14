void asm_instruction_reset(void)

{
  g_asm_instruction_code = 0;
  g_asm_mnemonic_code = 0;
  g_asm_operand_index = 0;
  g_asm_operands_begun = 0;
  g_asm_period_seen = 0;
  g_asm_in_brackets = 0;
  g_asm_unread_reset_word = 0;
  g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(0);
  return;
}

