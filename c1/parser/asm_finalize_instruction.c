void __cdecl asm_finalize_instruction(void)

{
  c1_symbol *pcVar1;
  short sVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = 0;
  g_asm_instruction.size_class = asm_instruction_size_class();
  bVar3 = g_asm_instruction.size_class;
  sVar2 = g_asm_opcode;
  switch(g_asm_form) {
  case 0:
    if (g_asm_opcode == 0xb8) {
      g_asm_opcode = 0xb5;
      sVar2 = g_asm_opcode;
    }
    break;
  case 2:
    if (((g_asm_operands[0].expr)->seg_scale & 0x3f) == 0x1c) {
      (g_asm_operands[0].expr)->seg_scale = (g_asm_operands[0].expr)->seg_scale & 0xc0;
    }
  case 10:
    sVar2 = g_asm_opcode;
    if (g_asm_operand_index < 1) break;
    switch(g_asm_opcode) {
    case 0x35:
      sVar2 = 0xe0;
      break;
    case 0x37:
      sVar2 = 0xe1;
      break;
    case 0x38:
      sVar2 = 0xe2;
      break;
    case 0x39:
      sVar2 = 0xe3;
      break;
    case 0x3c:
      sVar2 = 0xe4;
    }
    bVar3 = (g_asm_operands[0].expr)->seg_scale & 0x3f;
    if (g_asm_operand_index < 2) {
LAB_1064fafd:
      if (bVar3 != 0) goto LAB_1064fb01;
    }
    else {
      if (bVar3 == 0) {
        bVar3 = (g_asm_operands[1].expr)->seg_scale & 0x3f;
        goto LAB_1064fafd;
      }
LAB_1064fb01:
      if (g_asm_opcode != sVar2) break;
    }
    g_asm_operand_index = 0;
    sVar2 = g_asm_opcode;
    break;
  case 0xe:
  case 0xf:
    goto switchD_106238d8_caseD_e;
  case 0x10:
    g_asm_instruction.opcode_flags = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2];
  case 0x1b:
    bVar3 = 0;
switchD_106238d8_caseD_e:
    pcVar1 = (g_asm_operands[0].expr)->sym;
    if (((pcVar1 != (c1_symbol *)0x0) && (((g_asm_operands[0].expr)->kind & 0x10) == 0)) &&
       (bVar3 == 0)) {
      if (((g_asm_operands[0].expr)->disp == 0) || ((pcVar1->flags1 & 1) != 0)) {
        bVar3 = pcVar1->kind & 0x1f;
        if ((bVar3 == 7) || ((bVar3 == 8 || (bVar3 == 6)))) {
          diag_warning(3,0x19e,pcVar1);
          g_asm_instruction.size_class = '\x02';
          sVar2 = g_asm_opcode;
        }
      }
      else {
        diag_error(0x195);
        sVar2 = g_asm_opcode;
      }
    }
    break;
  case 0x11:
    if (g_asm_operand_index == 0) {
      g_asm_operand_index = 1;
      (g_asm_operands[0].expr)->kind = '\x02';
      (g_asm_operands[0].expr)->disp = 0;
      sVar2 = g_asm_opcode;
    }
    break;
  case 0x12:
    g_asm_operand_index = 2;
    g_asm_operand = asm_operand_reset(1);
    (g_asm_operands[1].expr)->kind = '\x02';
    (g_asm_operands[1].expr)->disp = 1;
    sVar2 = g_asm_opcode;
    break;
  case 0x14:
    if (g_asm_operand_index == 2) {
      g_asm_operands[2].size_class = g_asm_operands[1].size_class;
      g_asm_operands[2].flags = g_asm_operands[1].flags;
      g_asm_operands[2].pad06[0] = g_asm_operands[1].pad06[0];
      g_asm_operands[2].pad06[1] = g_asm_operands[1].pad06[1];
      g_asm_operands[2].sym = g_asm_operands[1].sym;
      g_asm_operands[2].frame_sym = g_asm_operands[1].frame_sym;
      g_asm_operand_index = 3;
      g_asm_operands[2].expr = g_asm_exprs + 2;
      g_asm_exprs[2].sym = (g_asm_operands[1].expr)->sym;
      g_asm_exprs[2].disp = (g_asm_operands[1].expr)->disp;
      g_asm_exprs[2].kind = (g_asm_operands[1].expr)->kind;
      g_asm_exprs[2].seg_scale = (g_asm_operands[1].expr)->seg_scale;
      g_asm_exprs[2].base = (g_asm_operands[1].expr)->base;
      g_asm_exprs[2].index = (g_asm_operands[1].expr)->index;
      g_asm_operands[1].size_class = g_asm_operands[0].size_class;
      g_asm_operands[1].flags = g_asm_operands[0].flags;
      g_asm_operands[1].pad06[0] = g_asm_operands[0].pad06[0];
      g_asm_operands[1].pad06[1] = g_asm_operands[0].pad06[1];
      g_asm_operands[1].sym = g_asm_operands[0].sym;
      g_asm_operands[1].frame_sym = g_asm_operands[0].frame_sym;
      g_asm_operands[1].expr = g_asm_exprs + 1;
      g_asm_exprs[1].sym = (g_asm_operands[0].expr)->sym;
      g_asm_exprs[1].disp = (g_asm_operands[0].expr)->disp;
      g_asm_exprs[1].kind = (g_asm_operands[0].expr)->kind;
      g_asm_exprs[1].seg_scale = (g_asm_operands[0].expr)->seg_scale;
      g_asm_exprs[1].base = (g_asm_operands[0].expr)->base;
      g_asm_exprs[1].index = (g_asm_operands[0].expr)->index;
    }
    break;
  case 0x1c:
    uVar4 = (uint)(g_asm_opcode == 10);
    break;
  case 0x1e:
    g_asm_instruction.opcode_flags = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2];
    break;
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x28:
  case 0x29:
  case 0x2b:
  case 0x2c:
    goto switchD_106238d8_caseD_1f;
  case 0x26:
  case 0x27:
  case 0x42:
  case 0x43:
  case 0x44:
    goto switchD_106238d8_caseD_26;
  case 0x32:
    g_asm_operand_index = 2;
    if (g_asm_kind_class[g_asm_kind_index[(g_asm_operands[2].expr)->kind & 0x1f]] == 2) {
      (g_asm_operands[1].expr)->disp = (g_asm_operands[2].expr)->disp;
      (g_asm_operands[1].expr)->kind = (g_asm_operands[1].expr)->kind | 2;
      sVar2 = g_asm_opcode;
    }
    break;
  case 0x33:
    if (g_asm_operands[1].size_class == '\x01') {
      sVar2 = (-(ushort)(g_asm_opcode != 0xc4) & 0xfffe) + 0xc5;
    }
    break;
  case 0x40:
    g_asm_instruction.opcode_flags = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2];
    break;
  case 0x41:
    if (g_asm_opcode == 0x106) {
      g_asm_instruction.opcode_flags = "Table_stack"[g_asm_mnemonic_opcode * 4 + 2];
    }
switchD_106238d8_caseD_1f:
    g_asm_instruction.size_class = g_asm_instruction.size_class | 0x20;
switchD_106238d8_caseD_26:
    uVar4 = asm_supply_float_operands();
    sVar2 = g_asm_opcode;
  }
  g_asm_opcode = sVar2;
  asm_encode_operand_registers();
  g_asm_instruction.exprs[0] = g_asm_exprs;
  g_asm_instruction.exprs[1] = g_asm_exprs + 1;
  g_asm_operand_order[0] = g_asm_operands;
  g_asm_operand_order[1] = g_asm_operands + 1;
  g_asm_operand_order[2] = g_asm_operands + 2;
  g_asm_instruction.exprs[2] = g_asm_exprs + 2;
  if (uVar4 == 0) {
    g_asm_instruction.code = g_asm_opcode;
    return;
  }
  asm_swap_words((int *)(g_asm_instruction.exprs + 1),(int *)g_asm_instruction.exprs);
  asm_swap_words((int *)g_asm_operands,(int *)(g_asm_operands + 1));
  asm_swap_words((int *)g_asm_operand_order,(int *)(g_asm_operand_order + 1));
  g_asm_instruction.code = g_asm_opcode;
  return;
}

