void __cdecl asm_instruction_begin(short op)

{
  g_asm_operand = g_asm_operands;
  g_asm_opcode = op;
  g_asm_operands[0].expr = g_asm_exprs;
  g_asm_form = g_asm_opcodes[op].form;
  return;
}

