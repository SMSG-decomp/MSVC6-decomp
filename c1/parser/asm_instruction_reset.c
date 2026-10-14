void asm_instruction_reset(void)

{
  g_asm_opcode = 0;
  g_asm_mnemonic_opcode = 0;
  g_asm_operand_index = 0;
  g_asm_operands_begun = 0;
  g_asm_after_period = 0;
  g_asm_in_brackets = 0;
  g_asm_cleared_word = 0;
  g_asm_operand = asm_operand_reset(0);
  return;
}

