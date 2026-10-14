char __cdecl asm_operands_size_class(void)

{
  char cVar1;
  c1_u8 cVar2;
  
  if ((((g_asm_opcode != g_asm_mnemonic_opcode) && (300 < g_asm_mnemonic_opcode)) &&
      (g_asm_mnemonic_opcode < 0x177)) &&
     (("Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0x30U) == 0)) {
    return "Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0xf;
  }
  if (g_asm_operand_index < 1) {
    cVar2 = '\x0f';
  }
  else {
    if (((((g_asm_operand_index == 2) &&
          (g_asm_operands[0].size_class != g_asm_operands[1].size_class)) &&
         ((g_asm_operands[1].size_class | g_asm_operands[0].size_class) != 0xf)) &&
        (((g_asm_form == 0xd || (g_asm_form == 6)) ||
         ((g_asm_form == 4 || (((g_asm_form == 5 || (g_asm_form == 0x37)) || (g_asm_form == 0x40))))
         )))) && ((g_asm_operands[1].expr)->sym != g_builtin_label_10)) {
      diag_error(0x1bb);
      cVar1 = asm_operands_size_class_fragment(g_asm_opcode,g_asm_operand_index);
      return cVar1;
    }
    cVar2 = g_asm_operands[1].size_class;
    if ((g_asm_opcode != 0xb) && (g_asm_opcode != 0x39)) {
      if ((g_asm_opcode == 0x35) || (g_asm_opcode == 0x38)) {
        if (g_asm_operands[0].size_class == '\x0f') {
          return g_asm_operands[1].size_class;
        }
      }
      else if (((g_asm_operand_index != 1) &&
               (g_asm_kind_class[g_asm_kind_index[(g_asm_operands[0].expr)->kind & 0x1f]] != 1)) &&
              ((g_asm_kind_class[g_asm_kind_index[(g_asm_operands[1].expr)->kind & 0x1f]] != 2 &&
               ((g_asm_form != 8 && (g_asm_opcode != 0x36)))))) {
        return g_asm_operands[1].size_class;
      }
      return g_asm_operands[0].size_class;
    }
  }
  return cVar2;
}

