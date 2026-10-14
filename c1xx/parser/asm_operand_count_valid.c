int __cdecl asm_operand_count_valid(void)

{
  if ((ushort)g_asm_operand_index == g_asm_forms[g_asm_operand_form] >> 0xe) {
    return 1;
  }
  switch(g_asm_operand_form) {
  case 2:
    if (g_asm_instruction_code != 0x3c) {
      return 0;
    }
  case 0x11:
switchD_104ba815_caseD_11:
    return (uint)(g_asm_operand_index == 1);
  case 9:
    if ((g_asm_instruction_code == 6) && (g_asm_operand_index != 0)) {
      if (g_asm_operand_index == 2) {
        g_asm_instruction_code =
             (-(ushort)(g_asm_mode_class
                        [g_asm_kind_mode[(g_asm_operand_slots[1].record)->kind & 0x1f]] != 2) & 0x1e
             ) + 0xa3;
      }
      else if (g_asm_operand_index == 3) {
        g_asm_instruction_code = 0xa3;
      }
      g_asm_operand_form = g_asm_instructions[g_asm_instruction_code].form;
      return 1;
    }
    break;
  case 10:
    if (g_asm_mnemonic_code != g_asm_instruction_code) {
      return 0;
    }
    if ((g_asm_instruction_code == 0x39) || (g_asm_instruction_code == 0x35)) {
      return (uint)(g_asm_operand_index == 2);
    }
  case 0x2b:
    if (((((g_asm_instruction_code != 0x37) && (g_asm_instruction_code != 0x3a)) &&
         (g_asm_instruction_code != 0x3b)) &&
        ((g_asm_instruction_code != 0x5c && (g_asm_instruction_code != 0xd1)))) &&
       ((g_asm_instruction_code != 0x52 &&
        ((g_asm_instruction_code != 0x5d && (g_asm_instruction_code != 0xd2)))))) {
      return (uint)(g_asm_operand_index < 3);
    }
    goto switchD_104ba815_caseD_11;
  case 0x28:
    if ((g_asm_operand_index == 0) && (g_asm_instruction_code == 0x5f)) {
      return 1;
    }
  }
  return 0;
}

