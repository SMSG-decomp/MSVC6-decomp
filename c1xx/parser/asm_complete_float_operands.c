int __cdecl asm_complete_float_operands(void)

{
  byte bVar1;
  short sVar2;
  int operand;
  
  sVar2 = g_asm_instruction_code;
  switch(g_asm_instruction_code) {
  case 0x45:
    sVar2 = 0x4b;
    break;
  case 0x46:
    sVar2 = 0x4c;
    break;
  case 0x47:
    sVar2 = 0x4d;
    break;
  case 0x48:
    sVar2 = 0x4e;
    break;
  case 0x49:
    sVar2 = 0x4f;
    break;
  case 0x4a:
    sVar2 = 0x50;
  }
  switch(g_asm_operand_form) {
  case 0x28:
    if (g_asm_instruction_code == 0x61) {
      return 0;
    }
    if (g_asm_operand_index == 0) {
      g_asm_operand_index = 1;
      g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(0);
      asm_check_float_register(0x1f,1);
      return 0;
    }
  case 0x2b:
    if (g_asm_operand_index == 0) {
      g_asm_operand_index = 1;
      g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(0);
      asm_check_float_register(0x1f,1);
      operand = g_asm_operand_index;
      g_asm_operand_index = g_asm_operand_index + 1;
      g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(operand);
      asm_check_float_register(0x1f,0);
      if (g_asm_operand_form == 0x2b) {
        g_asm_instruction_code = sVar2;
      }
      if ((((g_asm_instruction_code == 0x5c) || (g_asm_instruction_code == 0x5d)) ||
          (g_asm_instruction_code == 0xd1)) || (g_asm_instruction_code == 0xd2)) {
        return 1;
      }
    }
    else if ((g_asm_operand_index == 1) && (g_asm_operand_form != 0x28)) {
switchD_104b9e5e_caseD_42:
      g_asm_operand_index = 2;
      g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(1);
      asm_check_float_register(0x1f,0);
      return 1;
    }
    break;
  case 0x41:
    bVar1 = (g_asm_operand_slots[1].record)->base;
    g_asm_operand_index = 1;
    asm_operand_reset(1);
    g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(0);
    asm_check_float_register(0x1f,(uint)bVar1);
    break;
  case 0x42:
    goto switchD_104b9e5e_caseD_42;
  }
  return 0;
}

