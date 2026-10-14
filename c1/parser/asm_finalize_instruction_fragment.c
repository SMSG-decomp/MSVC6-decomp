void asm_finalize_instruction_fragment(int swap_operands)

{
  if (g_asm_opcode == 0xb8) {
    g_asm_opcode = 0xb5;
  }
  asm_encode_operand_registers();
  g_asm_instruction.exprs[0] = g_asm_exprs;
  g_asm_instruction.exprs[1] = g_asm_exprs + 1;
  g_asm_operand_order[0] = g_asm_operands;
  g_asm_operand_order[1] = g_asm_operands + 1;
  g_asm_operand_order[2] = g_asm_operands + 2;
  g_asm_instruction.exprs[2] = g_asm_exprs + 2;
  if (swap_operands == 0) {
    g_asm_instruction.code = g_asm_opcode;
    return;
  }
  asm_swap_words((int *)(g_asm_instruction.exprs + 1),(int *)g_asm_instruction.exprs);
  asm_swap_words((int *)g_asm_operands,(int *)(g_asm_operands + 1));
  asm_swap_words((int *)g_asm_operand_order,(int *)(g_asm_operand_order + 1));
  g_asm_instruction.code = g_asm_opcode;
  return;
}

