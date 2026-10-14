void asm_finalize_instruction_fragment(int esi)

{
  if (g_asm_instruction_code == 0xb8) {
    g_asm_instruction_code = 0xb5;
  }
  asm_encode_operand_registers();
  g_asm_emit_records[0] = g_asm_operand_records;
  g_asm_emit_records[1] = g_asm_operand_records + 1;
  g_asm_emit_slots[0] = g_asm_operand_slots;
  g_asm_emit_slots[1] = g_asm_operand_slots + 1;
  g_asm_emit_slots[2] = g_asm_operand_slots + 2;
  g_asm_emit_records[2] = g_asm_operand_records + 2;
  if (esi == 0) {
    g_asm_record_code = g_asm_instruction_code;
    return;
  }
  asm_swap_words((int *)(g_asm_emit_records + 1),(int *)g_asm_emit_records);
  asm_swap_words((int *)g_asm_operand_slots,(int *)(g_asm_operand_slots + 1));
  asm_swap_words((int *)g_asm_emit_slots,(int *)(g_asm_emit_slots + 1));
  g_asm_record_code = g_asm_instruction_code;
  return;
}

