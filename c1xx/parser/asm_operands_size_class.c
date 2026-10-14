char __cdecl asm_operands_size_class(void)

{
  char cVar1;
  c1_u8 cVar2;
  
  if ((((g_asm_instruction_code != g_asm_mnemonic_code) && (300 < g_asm_mnemonic_code)) &&
      (g_asm_mnemonic_code < 0x177)) &&
     (("\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16] & 0x30U) ==
      0)) {
    return "\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16] & 0xf;
  }
  if (g_asm_operand_index < 1) {
    cVar2 = '\x0f';
  }
  else {
    if (((((g_asm_operand_index == 2) &&
          (g_asm_operand_slots[0].size_class != g_asm_operand_slots[1].size_class)) &&
         ((g_asm_operand_slots[1].size_class | g_asm_operand_slots[0].size_class) != 0xf)) &&
        (((g_asm_operand_form == 0xd || (g_asm_operand_form == 6)) ||
         ((g_asm_operand_form == 4 ||
          (((g_asm_operand_form == 5 || (g_asm_operand_form == 0x37)) ||
           (g_asm_operand_form == 0x40)))))))) &&
       ((g_asm_operand_slots[1].record)->sym != g_builtin_label_10)) {
      diag_error(0x1bb);
      cVar1 = asm_operands_size_class_fragment(g_asm_instruction_code,g_asm_operand_index);
      return cVar1;
    }
    cVar2 = g_asm_operand_slots[1].size_class;
    if ((g_asm_instruction_code != 0xb) && (g_asm_instruction_code != 0x39)) {
      if ((g_asm_instruction_code == 0x35) || (g_asm_instruction_code == 0x38)) {
        if (g_asm_operand_slots[0].size_class == '\x0f') {
          return g_asm_operand_slots[1].size_class;
        }
      }
      else if (((g_asm_operand_index != 1) &&
               (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[0].record)->kind & 0x1f]] != 1
               )) && ((g_asm_mode_class
                       [g_asm_kind_mode[(g_asm_operand_slots[1].record)->kind & 0x1f]] != 2 &&
                      ((g_asm_operand_form != 8 && (g_asm_instruction_code != 0x36)))))) {
        return g_asm_operand_slots[1].size_class;
      }
      return g_asm_operand_slots[0].size_class;
    }
  }
  return cVar2;
}

