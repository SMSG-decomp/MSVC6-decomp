char __cdecl asm_instruction_size_class(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  c1_asm_operand_slot *slot;
  
  bVar1 = asm_operands_size_class();
  switch(g_asm_operand_form) {
  case 7:
    if (g_asm_instruction_code != 0x12) {
      if (bVar1 == 1) {
        bVar2 = 2;
      }
      else {
        bVar2 = (-(g_asm_instruction_code != 3) & 2U) + 3;
      }
      goto LAB_104b9a94;
    }
    goto LAB_104563b9;
  case 0xf:
    if (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[0].record)->kind & 0x1f]] != 0) break;
    if ((bVar1 == 0) || (bVar1 == 0xf)) {
      bVar1 = 1;
      goto LAB_104b9a41;
    }
    goto LAB_104563c2;
  case 0x15:
    if ((g_asm_instruction_code == 0x3e) || (bVar1 = 5, g_asm_instruction_code == 0x41)) {
      bVar1 = 1;
    }
    slot = g_asm_operand_slots;
    bVar2 = bVar1;
    goto LAB_104b9a79;
  case 0x17:
    bVar2 = bVar1;
LAB_104b9a94:
    slot = g_asm_operand_slots + 1;
LAB_104b9a79:
    iVar3 = asm_slot_size_matches(slot,bVar2);
    if (iVar3 == 0) {
LAB_104b9a41:
      diag_warning(1,0x19a);
    }
    break;
  case 0x1b:
    if (g_asm_instruction_code == 0x16) {
      bVar1 = (g_asm_mnemonic_code != 0x16) + 1;
    }
    else {
      bVar1 = 0;
    }
    goto LAB_104563c2;
  case 0x29:
    if ((g_asm_instruction_code == 0x62) &&
       (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[0].record)->kind & 0x1f]] == 0)) {
      if (g_asm_operand_slots[0].size_class == '\x0f') {
        bVar1 = 3;
        goto LAB_104563c2;
      }
      bVar1 = g_asm_operand_slots[0].size_class;
      if (g_asm_operand_slots[0].size_class == '\x04') {
        bVar1 = 3;
        goto LAB_104b9a41;
      }
    }
    goto LAB_104563b9;
  case 0x2b:
    if (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[0].record)->kind & 0x1f]] == 0) {
      bVar1 = g_asm_operand_slots[0].size_class;
      if (g_asm_operand_slots[0].size_class == '\x0f') {
        bVar1 = 3;
      }
      iVar3 = asm_slot_symbol_type_test(g_asm_operand_slots,0x20);
      if ((iVar3 == 0) || (((bVar1 != 2 && (bVar1 != 3)) && (bVar1 != 4)))) goto LAB_104b9a41;
    }
    break;
  case 0x42:
  case 0x43:
    bVar1 = g_asm_operand_slots[0].size_class;
    if (g_asm_operand_slots[0].size_class == '\x0f') {
      bVar1 = 1;
    }
    iVar3 = asm_slot_symbol_type_test(g_asm_operand_slots,0x10);
    if (iVar3 != 0) {
      if ((bVar1 == 1) || (bVar1 == 2)) break;
      if ((bVar1 == 3) && (g_asm_operand_form == 0x43)) goto LAB_104563c2;
    }
    goto LAB_104b9a41;
  }
LAB_104563b9:
  if (bVar1 != 0xf) {
LAB_104563c2:
    if (((uint)g_asm_forms[g_asm_operand_form] & 1 << (bVar1 + 8 & 0x1f)) != 0) {
      if ((((g_asm_instruction_code != g_asm_mnemonic_code) && (300 < g_asm_mnemonic_code)) &&
          (g_asm_mnemonic_code < 0x177)) &&
         (("\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16] & 0x30U
          ) != 0)) {
        bVar1 = "\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16] &
                0xf;
      }
      return bVar1;
    }
    if ((g_asm_instruction_code == 0x104) && (bVar1 == 1)) {
      g_asm_instruction_code = 0x105;
      return '\x01';
    }
    diag_warning(1,0x199);
  }
  bVar2 = 0;
  bVar1 = bVar2;
  if ((g_asm_forms[g_asm_operand_form] & 0x100) == 0) {
    do {
      bVar2 = bVar1 + 1;
      bVar4 = bVar1 + 9;
      bVar1 = bVar2;
    } while ((g_asm_forms[g_asm_operand_form] & 0x3f00 & 1 << (bVar4 & 0x1f)) == 0);
  }
  if (((g_asm_instruction_code != g_asm_mnemonic_code) && (300 < g_asm_mnemonic_code)) &&
     ((g_asm_mnemonic_code < 0x177 &&
      (("\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16] & 0x30U)
       != 0)))) {
    bVar2 = "\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16] & 0xf;
  }
  switch(g_asm_operand_form) {
  case 0:
    switch(g_asm_mnemonic_code) {
    case 0x99:
      return '\0';
    default:
      break;
    case 0x9f:
    case 0x143:
      return '\x01';
    case 0x142:
      goto switchD_104b9ca6_caseD_b;
    }
  case 1:
    if (g_asm_mnemonic_code == 0xa5) {
      return '\x01';
    }
    if ((0xa9 < g_asm_mnemonic_code) && (g_asm_mnemonic_code < 0xae)) {
      return '\x01';
    }
    break;
  case 0xb:
switchD_104b9ca6_caseD_b:
    bVar2 = 2;
    break;
  case 0x26:
  case 0x27:
    return '\x04';
  }
  return bVar2;
}

