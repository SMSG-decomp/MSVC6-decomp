int __cdecl asm_operand_kinds_valid(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  c1_asm_operand_slot *pcVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  c1_asm_operand_slot *pcVar9;
  char cVar10;
  
  bVar1 = (g_asm_operand_slots[0].record)->kind;
  uVar8 = (uint)g_asm_mode_class[g_asm_kind_mode[bVar1 & 0x1f]];
  if (1 < g_asm_operand_index) {
    uVar8 = (uint)g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[1].record)->kind & 0x1f]] +
            uVar8 * 3;
  }
  uVar6 = 1 << ((byte)uVar8 & 0x1f);
  if (uVar8 < 6) {
    if ((uVar6 & g_asm_forms[g_asm_operand_form]) == 0) {
      return 0;
    }
  }
  else if (((g_asm_instruction_code != 0xb) && (g_asm_instruction_code != 5)) &&
          (g_asm_instruction_code != 4)) {
    return 0;
  }
  uVar7 = uVar6 & 0x3a;
  if (uVar7 != 0) {
    if ((g_asm_operand_index < 2) ||
       ((g_asm_registers[(g_asm_operand_slots[1].record)->base] & 0xc0) != 0x40)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    bVar5 = ((g_asm_registers[(g_asm_operand_slots[0].record)->base] & 0xc0) == 0x40) + cVar10;
    if ((bVar5 != 0) && ((1 < bVar5 || ((g_asm_forms[g_asm_operand_form] & 0xc0) != 0x40)))) {
      return 0;
    }
  }
  if ((g_asm_forms[g_asm_operand_form] & 0xc0) != 0xc0) {
    if ((uVar7 != 0) &&
       ((g_asm_registers[(g_asm_operand_slots[0].record)->base] & 0x80c0) == 0x8080)) {
      return 0;
    }
    if (((uVar6 & 0x10) != 0) &&
       ((g_asm_registers[(g_asm_operand_slots[1].record)->base] & 0x80c0) == 0x8080)) {
      iVar3 = asm_operand_kinds_valid_fragment();
      return iVar3;
    }
  }
  if ((g_asm_forms[g_asm_operand_form] & 0xc0) == 0x80) {
    if ((uVar7 != 0) && ((bVar1 & 0x34) == 0)) {
      return 0;
    }
    if (((uVar6 & 0x10) != 0) && (((g_asm_operand_slots[1].record)->kind & 0x34) == 0)) {
      return 0;
    }
  }
  switch(g_asm_operand_form) {
  case 8:
    if ((uVar6 & 0x24) == 0) {
      if ((g_asm_operand_slots[1].record)->base != '\x12') {
        return 0;
      }
    }
    else {
      if ((g_target_cpu_mask == 1) && ((g_asm_operand_slots[1].record)->value != 1)) {
        return 0;
      }
      if ((((g_asm_operand_slots[1].record)->kind & 1) != 0) ||
         (iVar3 = asm_value_fits_bits('\b',(g_asm_operand_slots[1].record)->value), iVar3 == 0)) {
        return 0;
      }
    }
    break;
  case 10:
    if ((g_asm_instruction_code == 0x39) || (g_asm_instruction_code == 0x35)) {
      pcVar4 = g_asm_operand_slots + 1;
      pcVar9 = g_asm_operand_slots;
    }
    else {
      pcVar4 = g_asm_operand_slots;
      pcVar9 = g_asm_operand_slots + 1;
    }
    if ((g_asm_instruction_code != 0x39) && (g_asm_instruction_code != 0x37)) {
      bVar1 = pcVar4->record->seg_scale;
      bVar5 = bVar1 & 0x3f;
      if (bVar5 != 0) {
        if (bVar5 != 0x19) {
          return 0;
        }
        pcVar4->record->seg_scale = bVar1 & 0xc0;
      }
    }
    bVar1 = pcVar4->record->seg_scale;
    if ((bVar1 & 0x3f) == 0x1c) {
      pcVar4->record->seg_scale = bVar1 & 0xc0;
    }
    if (g_asm_operand_index == 2) {
      bVar1 = pcVar9->record->seg_scale;
      if ((bVar1 & 0x3f) == 0x1c) {
        pcVar9->record->seg_scale = bVar1 & 0xc0;
      }
      if (((g_asm_instruction_code == 0x39) || (g_asm_instruction_code == 0x36)) &&
         (pcVar9->record->base != '\v')) {
        return 0;
      }
    }
    break;
  case 0xb:
    if ((g_target_cpu_mask == 1) && (uVar8 == 2)) {
      return 0;
    }
    break;
  case 0xd:
    uVar2 = g_asm_registers[(g_asm_operand_slots[0].record)->base] & 0xc0;
    if ((uVar2 == 0xc0) || ((g_asm_registers[(g_asm_operand_slots[1].record)->base] & 0xc0) == 0xc0)
       ) {
      if ((uVar8 == 4) &&
         ((uVar2 != 0xc0 ||
          ((g_asm_registers[(g_asm_operand_slots[1].record)->base] & 0xc0) != 0xc0)))) {
        g_asm_instruction_code = 0xd0;
        g_asm_operand_form = 0x35;
        return 1;
      }
      return 0;
    }
    if ((uVar8 == 5) && (uVar2 == 0x40)) {
      return 0;
    }
  case 0xc:
    if ((uVar7 != 0) && ((g_asm_operand_slots[0].record)->base == '\x1a')) {
      return 0;
    }
    break;
  case 0xe:
  case 0xf:
    if ((uVar8 == 2) && ((bVar1 & 1) == 0)) {
      return 0;
    }
    break;
  case 0x13:
    if (uVar8 == 8) {
      iVar3 = asm_value_fits_bits('\b',(g_asm_operand_slots[1].record)->value);
      return iVar3;
    }
    return 0;
  case 0x14:
    if (g_target_cpu_mask == 1) {
      return 0;
    }
    if (uVar7 == 0) {
      return 0;
    }
    if ((g_target_cpu_mask != 8) && ((g_asm_operand_index == 2) != (uVar8 == 5))) {
      return 0;
    }
    break;
  case 0x19:
    if (g_asm_mode_class[g_asm_kind_mode[bVar1 & 0x1f]] != 2) {
      return 0;
    }
    iVar3 = asm_value_fits_bits('\x06',(g_asm_operand_slots[0].record)->value);
    if (iVar3 == 0) {
      return 0;
    }
    if ((uVar8 == 8) ||
       ((uVar8 == 7 && ((g_asm_registers[(g_asm_operand_slots[1].record)->base] & 0xc0) == 0x40))))
    {
      return 0;
    }
    break;
  case 0x1a:
    iVar3 = asm_value_fits_bits('\b',(g_asm_operand_slots[0].record)->value);
    return iVar3;
  case 0x1b:
    if ((g_asm_operand_slots[0].record)->value == 0) {
      return bVar1 & 1;
    }
    return 0;
  case 0x1c:
    if (g_asm_instruction_code == 0xb) {
      pcVar4 = g_asm_operand_slots + 1;
      pcVar9 = g_asm_operand_slots;
    }
    else {
      pcVar4 = g_asm_operand_slots;
      pcVar9 = g_asm_operand_slots + 1;
    }
    if (g_asm_mode_class[g_asm_kind_mode[pcVar4->record->kind & 0x1f]] != 1) {
      return 0;
    }
    if ((*(byte *)((int)g_asm_registers + (uint)pcVar4->record->base * 2 + 1) & 0x10) == 0) {
      return 0;
    }
    if ((g_asm_mode_class[g_asm_kind_mode[pcVar9->record->kind & 0x1f]] != 2) ||
       (iVar3 = asm_value_fits_bits('\b',pcVar9->record->value), iVar3 == 0)) {
      if (g_asm_mode_class[g_asm_kind_mode[pcVar9->record->kind & 0x1f]] != 1) {
        return 0;
      }
      if (pcVar9->record->base != '\v') {
        return 0;
      }
    }
    break;
  case 0x26:
  case 0x27:
    if (((g_asm_instruction_code != 0x6e) && (g_asm_instruction_code != 0x6c)) ||
       ((g_asm_operand_slots[0].record)->base != '\t')) {
      return (uint)(uVar8 == 0);
    }
    break;
  case 0x2b:
  case 0x2c:
    if ((((g_asm_instruction_code == 0x5c) || (g_asm_instruction_code == 0x5d)) ||
        (g_asm_instruction_code == 0xd1)) || (g_asm_instruction_code == 0xd2)) {
      if (uVar8 == 4) {
        return 0;
      }
    }
    else if (g_asm_operand_index == 2) {
      if (uVar8 != 4) {
        return 0;
      }
      if (((g_asm_operand_slots[1].record)->base != '\0') &&
         ((g_asm_operand_form == 0x2c || ((g_asm_operand_slots[0].record)->base != '\0')))) {
        return 0;
      }
    }
    else if (uVar8 != 0) {
      return 0;
    }
    break;
  case 0x32:
    if (((g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[2].record)->kind & 0x1f]] != 2) ||
        (iVar3 = asm_value_fits_bits('\b',(g_asm_operand_slots[2].record)->value), iVar3 == 0)) &&
       ((g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[2].record)->kind & 0x1f]] != 1 ||
        ((g_asm_operand_slots[2].record)->base != '\x12')))) {
      return 0;
    }
    break;
  case 0x34:
    if (g_asm_mode_class[g_asm_kind_mode[(g_asm_operand_slots[1].record)->kind & 0x1f]] == 2) {
      if (((g_asm_operand_slots[1].record)->kind & 1) != 0) {
        return 0;
      }
      iVar3 = asm_value_fits_bits('\b',(g_asm_operand_slots[1].record)->value);
      if (iVar3 == 0) {
        return 0;
      }
    }
    break;
  case 0x41:
    if (uVar8 != 4) {
      return 0;
    }
    if ((g_asm_operand_slots[0].record)->base != '\0') {
      return 0;
    }
  }
  return 1;
}

