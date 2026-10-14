char __cdecl asm_instruction_size_class(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  c1_asm_operand *operand;
  
  bVar1 = asm_operands_size_class();
  switch(g_asm_form) {
  case 7:
    if (g_asm_opcode == 0x12) goto LAB_10623995;
    if (bVar1 == 1) {
      bVar3 = 2;
    }
    else {
      bVar3 = (-(g_asm_opcode != 3) & 2U) + 3;
    }
    goto LAB_1064f440;
  default:
    goto code_r0x1062398e;
  case 0xf:
    if (g_asm_kind_class[g_asm_kind_index[(g_asm_operands[0].expr)->kind & 0x1f]] != 0)
    goto code_r0x1062398e;
    if ((bVar1 == 0) || (bVar1 == 0xf)) {
      bVar1 = 1;
      goto LAB_1064f3ed;
    }
    break;
  case 0x15:
    if ((g_asm_opcode == 0x3e) || (bVar1 = 5, g_asm_opcode == 0x41)) {
      bVar1 = 1;
    }
    operand = g_asm_operands;
    bVar3 = bVar1;
    goto LAB_1064f425;
  case 0x17:
    bVar3 = bVar1;
LAB_1064f440:
    operand = g_asm_operands + 1;
LAB_1064f425:
    iVar4 = asm_operand_size_matches(operand,bVar3);
    if (iVar4 != 0) {
      cVar2 = asm_instruction_size_class_fragment(bVar1);
      return cVar2;
    }
LAB_1064f3ed:
    diag_warning(1,0x19a);
    cVar2 = asm_instruction_size_class_fragment(bVar1);
    return cVar2;
  case 0x1b:
    if (g_asm_opcode == 0x16) {
      bVar1 = (g_asm_mnemonic_opcode != 0x16) + 1;
    }
    else {
      bVar1 = 0;
    }
    break;
  case 0x29:
    if ((g_asm_opcode == 0x62) &&
       (g_asm_kind_class[g_asm_kind_index[(g_asm_operands[0].expr)->kind & 0x1f]] == 0)) {
      if (g_asm_operands[0].size_class == '\x0f') {
        bVar1 = 3;
        break;
      }
      bVar1 = g_asm_operands[0].size_class;
      if (g_asm_operands[0].size_class == '\x04') {
        bVar1 = 3;
        goto LAB_1064f3ed;
      }
    }
    goto LAB_10623995;
  case 0x2b:
    if (g_asm_kind_class[g_asm_kind_index[(g_asm_operands[0].expr)->kind & 0x1f]] == 0) {
      bVar1 = g_asm_operands[0].size_class;
      if (g_asm_operands[0].size_class == '\x0f') {
        bVar1 = 3;
      }
      iVar4 = asm_operand_type_allows_size(g_asm_operands,0x20);
      if ((iVar4 == 0) || (((bVar1 != 2 && (bVar1 != 3)) && (bVar1 != 4)))) goto LAB_1064f3ed;
    }
    goto code_r0x1062398e;
  case 0x42:
  case 0x43:
    bVar1 = g_asm_operands[0].size_class;
    if (g_asm_operands[0].size_class == '\x0f') {
      bVar1 = 1;
    }
    iVar4 = asm_operand_type_allows_size(g_asm_operands,0x10);
    if (iVar4 == 0) goto LAB_1064f3ed;
    if ((bVar1 == 1) || (bVar1 == 2)) goto code_r0x1062398e;
    if ((bVar1 != 3) || (g_asm_form != 0x43)) goto LAB_1064f3ed;
  }
LAB_1062399e:
  if (((uint)g_asm_form_words[g_asm_form] & 1 << (bVar1 + 8 & 0x1f)) != 0) {
    if ((((g_asm_opcode != g_asm_mnemonic_opcode) && (300 < g_asm_mnemonic_opcode)) &&
        (g_asm_mnemonic_opcode < 0x177)) &&
       (("Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0x30U) != 0)) {
      bVar1 = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0xf;
    }
    return bVar1;
  }
  if ((g_asm_opcode == 0x104) && (bVar1 == 1)) {
    g_asm_opcode = 0x105;
    return '\x01';
  }
  diag_warning(1,0x199);
LAB_1064f5e9:
  bVar3 = 0;
  bVar1 = bVar3;
  if ((g_asm_form_words[g_asm_form] & 0x100) == 0) {
    do {
      bVar3 = bVar1 + 1;
      bVar5 = bVar1 + 9;
      bVar1 = bVar3;
    } while ((g_asm_form_words[g_asm_form] & 0x3f00 & 1 << (bVar5 & 0x1f)) == 0);
  }
  if (((g_asm_opcode != g_asm_mnemonic_opcode) && (300 < g_asm_mnemonic_opcode)) &&
     ((g_asm_mnemonic_opcode < 0x177 &&
      (("Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0x30U) != 0)))) {
    bVar3 = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2] & 0xf;
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
    bVar3 = 2;
    break;
  case 0x26:
  case 0x27:
    return '\x04';
  }
  return bVar3;
code_r0x1062398e:
LAB_10623995:
  if (bVar1 != 0xf) goto LAB_1062399e;
  goto LAB_1064f5e9;
}

