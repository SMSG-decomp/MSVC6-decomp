void __cdecl asm_instruction_begin(short op)

{
  g_asm_current_operand = g_asm_operand_slots;
  g_asm_instruction_code = op;
  g_asm_operand_slots[0].record = g_asm_operand_records;
  g_asm_operand_form = g_asm_instructions[op].form;
  return;
}

