void asm_finalize_instruction(void)

{
  c1_symbol *pcVar1;
  short sVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = 0;
  g_asm_size_class = asm_instruction_size_class();
  bVar3 = g_asm_size_class;
  sVar2 = g_asm_instruction_code;
  switch(g_asm_operand_form) {
  case 0:
    if (g_asm_instruction_code == 0xb8) {
      g_asm_instruction_code = 0xb5;
      sVar2 = g_asm_instruction_code;
    }
    break;
  case 2:
    if (((g_asm_operand_slots[0].record)->seg_scale & 0x3f) == 0x1c) {
      (g_asm_operand_slots[0].record)->seg_scale = (g_asm_operand_slots[0].record)->seg_scale & 0xc0
      ;
    }
  case 10:
    sVar2 = g_asm_instruction_code;
    if (g_asm_operand_index < 1) break;
    switch(g_asm_instruction_code) {
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
    bVar3 = (g_asm_operand_slots[0].record)->seg_scale & 0x3f;
    if (g_asm_operand_index < 2) {
LAB_104ba14d:
      if (bVar3 != 0) goto LAB_104ba151;
    }
    else {
      if (bVar3 == 0) {
        bVar3 = (g_asm_operand_slots[1].record)->seg_scale & 0x3f;
        goto LAB_104ba14d;
      }
LAB_104ba151:
      if (g_asm_instruction_code != sVar2) break;
    }
    g_asm_operand_index = 0;
    sVar2 = g_asm_instruction_code;
    break;
  case 0xe:
  case 0xf:
    goto switchD_104562fc_caseD_e;
  case 0x10:
    g_asm_condition_code =
         "\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16];
  case 0x1b:
    bVar3 = 0;
switchD_104562fc_caseD_e:
    pcVar1 = (g_asm_operand_slots[0].record)->sym;
    if (((pcVar1 != (c1_symbol *)0x0) && (((g_asm_operand_slots[0].record)->kind & 0x10) == 0)) &&
       (bVar3 == 0)) {
      if (((g_asm_operand_slots[0].record)->value == 0) || ((pcVar1->flags2 & 4) != 0)) {
        bVar3 = pcVar1->kind & 0x1f;
        if ((bVar3 == 7) || ((bVar3 == 8 || (bVar3 == 6)))) {
          diag_warning(3,0x19e,pcVar1);
          g_asm_size_class = '\x02';
          sVar2 = g_asm_instruction_code;
        }
      }
      else {
        diag_error(0x195);
        sVar2 = g_asm_instruction_code;
      }
    }
    break;
  case 0x11:
    if (g_asm_operand_index == 0) {
      g_asm_operand_index = 1;
      (g_asm_operand_slots[0].record)->kind = '\x02';
      (g_asm_operand_slots[0].record)->value = 0;
      sVar2 = g_asm_instruction_code;
    }
    break;
  case 0x12:
    g_asm_operand_index = 2;
    g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(1);
    (g_asm_operand_slots[1].record)->kind = '\x02';
    (g_asm_operand_slots[1].record)->value = 1;
    sVar2 = g_asm_instruction_code;
    break;
  case 0x14:
    if (g_asm_operand_index == 2) {
      g_asm_operand_slots[2].size_class = g_asm_operand_slots[1].size_class;
      g_asm_operand_slots[2].size_given = g_asm_operand_slots[1].size_given;
      g_asm_operand_slots[2].x06[0] = g_asm_operand_slots[1].x06[0];
      g_asm_operand_slots[2].x06[1] = g_asm_operand_slots[1].x06[1];
      g_asm_operand_slots[2].ref_symbol = g_asm_operand_slots[1].ref_symbol;
      g_asm_operand_slots[2].frame_symbol = g_asm_operand_slots[1].frame_symbol;
      g_asm_operand_index = 3;
      g_asm_operand_slots[2].record = g_asm_operand_records + 2;
      g_asm_operand_records[2].sym = (g_asm_operand_slots[1].record)->sym;
      g_asm_operand_records[2].value = (g_asm_operand_slots[1].record)->value;
      g_asm_operand_records[2].kind = (g_asm_operand_slots[1].record)->kind;
      g_asm_operand_records[2].seg_scale = (g_asm_operand_slots[1].record)->seg_scale;
      g_asm_operand_records[2].base = (g_asm_operand_slots[1].record)->base;
      g_asm_operand_records[2].index = (g_asm_operand_slots[1].record)->index;
      g_asm_operand_slots[1].size_class = g_asm_operand_slots[0].size_class;
      g_asm_operand_slots[1].size_given = g_asm_operand_slots[0].size_given;
      g_asm_operand_slots[1].x06[0] = g_asm_operand_slots[0].x06[0];
      g_asm_operand_slots[1].x06[1] = g_asm_operand_slots[0].x06[1];
      g_asm_operand_slots[1].ref_symbol = g_asm_operand_slots[0].ref_symbol;
      g_asm_operand_slots[1].frame_symbol = g_asm_operand_slots[0].frame_symbol;
      g_asm_operand_slots[1].record = g_asm_operand_records + 1;
      g_asm_operand_records[1].sym = (g_asm_operand_slots[0].record)->sym;
      g_asm_operand_records[1].value = (g_asm_operand_slots[0].record)->value;
      g_asm_operand_records[1].kind = (g_asm_operand_slots[0].record)->kind;
      g_asm_operand_records[1].seg_scale = (g_asm_operand_slots[0].record)->seg_scale;
      g_asm_operand_records[1].base = (g_asm_operand_slots[0].record)->base;
      g_asm_operand_records[1].index = (g_asm_operand_slots[0].record)->index;
    }
    break;
  case 0x1c:
    uVar4 = (uint)(g_asm_instruction_code == 10);
    break;
  case 0x1e:
    g_asm_condition_code =
         "\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16];
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
    goto switchD_104562fc_caseD_1f;
  case 0x26:
  case 0x27:
  case 0x42:
  case 0x43:
  case 0x44:
    goto switchD_104562fc_caseD_26;
  case 0x32:
    g_asm_operand_index = 2;
    if (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[2].record)->kind & 0x1f]] == 2) {
      (g_asm_operand_slots[1].record)->value = (g_asm_operand_slots[2].record)->value;
      (g_asm_operand_slots[1].record)->kind = (g_asm_operand_slots[1].record)->kind | 2;
      sVar2 = g_asm_instruction_code;
    }
    break;
  case 0x33:
    if (g_asm_operand_slots[1].size_class == '\x01') {
      sVar2 = (-(ushort)(g_asm_instruction_code != 0xc4) & 0xfffe) + 0xc5;
    }
    break;
  case 0x40:
    g_asm_condition_code =
         "\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16];
    break;
  case 0x41:
    if (g_asm_instruction_code == 0x106) {
      g_asm_condition_code =
           "\n//\n// Cross-referenced type libraries:\n//\n"[g_asm_mnemonic_code * 4 + 0x16];
    }
switchD_104562fc_caseD_1f:
    g_asm_size_class = g_asm_size_class | 0x20;
switchD_104562fc_caseD_26:
    uVar4 = asm_complete_float_operands();
    sVar2 = g_asm_instruction_code;
  }
  g_asm_instruction_code = sVar2;
  asm_encode_operand_registers();
  g_asm_emit_records[0] = g_asm_operand_records;
  g_asm_emit_records[1] = g_asm_operand_records + 1;
  g_asm_emit_slots[0] = g_asm_operand_slots;
  g_asm_emit_slots[1] = g_asm_operand_slots + 1;
  g_asm_emit_slots[2] = g_asm_operand_slots + 2;
  g_asm_emit_records[2] = g_asm_operand_records + 2;
  if (uVar4 == 0) {
    g_asm_record_code = g_asm_instruction_code;
    return;
  }
  asm_swap_words((int *)(g_asm_emit_records + 1),(int *)g_asm_emit_records);
  asm_swap_words((int *)g_asm_operand_slots,(int *)(g_asm_operand_slots + 1));
  asm_swap_words((int *)g_asm_emit_slots,(int *)(g_asm_emit_slots + 1));
  g_asm_record_code = g_asm_instruction_code;
  return;
}

