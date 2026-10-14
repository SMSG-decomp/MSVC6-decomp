char asm_warn_instruction_size(c1_u8 size_class)

{
  char cVar1;
  byte bVar2;
  int iVar4;
  byte bVar5;
  byte bVar3;
  
  if (g_asm_opcode != 0x12) {
    if (size_class == '\x01') {
      cVar1 = '\x02';
    }
    else {
      cVar1 = (-(g_asm_opcode != 3) & 2U) + 3;
    }
    iVar4 = asm_operand_size_matches(g_asm_operands + 1,cVar1);
    if (iVar4 != 0) {
      cVar1 = asm_instruction_size_class_fragment(size_class);
      return cVar1;
    }
    diag_warning(1,0x19a);
    cVar1 = asm_instruction_size_class_fragment(size_class);
    return cVar1;
  }
  if (size_class != '\x0f') {
    if (((uint)g_asm_form_words[g_asm_form] & 1 << (size_class + 8 & 0x1f)) != 0) {
      if ((((g_asm_mnemonic_opcode != 0x12) && (300 < g_asm_mnemonic_opcode)) &&
          (g_asm_mnemonic_opcode < 0x177)) &&
         (("Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0x30U) != 0)) {
        size_class = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0xf;
      }
      return size_class;
    }
    diag_warning(1,0x199);
  }
  bVar2 = 0;
  bVar3 = bVar2;
  if ((g_asm_form_words[g_asm_form] & 0x100) == 0) {
    do {
      bVar2 = bVar3 + 1;
      bVar5 = bVar3 + 9;
      bVar3 = bVar2;
    } while ((g_asm_form_words[g_asm_form] & 0x3f00 & 1 << (bVar5 & 0x1f)) == 0);
  }
  if (((g_asm_opcode != g_asm_mnemonic_opcode) && (300 < g_asm_mnemonic_opcode)) &&
     ((g_asm_mnemonic_opcode < 0x177 &&
      (("Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0x30U) != 0)))) {
    bVar2 = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0xf;
  }
  switch(g_asm_form) {
  case 0:
    switch(g_asm_mnemonic_opcode) {
    case 0x99:
      return '\0';
    default:
      break;
    case 0x9f:
    case 0x143:
      return '\x01';
    case 0x142:
      goto switchD_1064f652_caseD_b;
    }
  case 1:
    if (g_asm_mnemonic_opcode == 0xa5) {
      return '\x01';
    }
    if ((0xa9 < g_asm_mnemonic_opcode) && (g_asm_mnemonic_opcode < 0xae)) {
      return '\x01';
    }
    break;
  case 0xb:
switchD_1064f652_caseD_b:
    bVar2 = 2;
    break;
  case 0x26:
  case 0x27:
    return '\x04';
  }
  return bVar2;
}

