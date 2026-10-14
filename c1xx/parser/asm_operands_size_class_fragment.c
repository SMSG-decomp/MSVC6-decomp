char asm_operands_size_class_fragment(short instruction_code,int operand_count)

{
  if ((instruction_code == 0xb) || (instruction_code == 0x39)) {
    return g_asm_operand_slots[1].size_class;
  }
  if ((instruction_code == 0x35) || (instruction_code == 0x38)) {
    if (g_asm_operand_slots[0].size_class == '\x0f') {
      return g_asm_operand_slots[1].size_class;
    }
  }
  else if ((((operand_count != 1) &&
            (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[0].record)->kind & 0x1f]] != 1))
           && (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[1].record)->kind & 0x1f]] != 2)
           ) && ((g_asm_operand_form != 8 && (instruction_code != 0x36)))) {
    return g_asm_operand_slots[1].size_class;
  }
  return g_asm_operand_slots[0].size_class;
}

