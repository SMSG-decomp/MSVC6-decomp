char asm_operands_size_class_fragment(short opcode,int operand_count)

{
  if ((opcode == 0xb) || (opcode == 0x39)) {
    return g_asm_operands[1].size_class;
  }
  if ((opcode == 0x35) || (opcode == 0x38)) {
    if (g_asm_operands[0].size_class == '\x0f') {
      return g_asm_operands[1].size_class;
    }
  }
  else if ((((operand_count != 1) &&
            (g_asm_kind_class[g_asm_kind_index[(g_asm_operands[0].expr)->kind & 0x1f]] != 1)) &&
           (g_asm_kind_class[g_asm_kind_index[(g_asm_operands[1].expr)->kind & 0x1f]] != 2)) &&
          ((g_asm_form != 8 && (opcode != 0x36)))) {
    return g_asm_operands[1].size_class;
  }
  return g_asm_operands[0].size_class;
}

