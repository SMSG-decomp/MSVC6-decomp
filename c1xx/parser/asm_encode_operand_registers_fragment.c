void asm_encode_operand_registers_fragment
               (c1_u8 esp_code,int operand_count,c1_asm_operand_slot *slot)

{
  byte bVar1;
  c1_asm_operand *pcVar2;
  c1_asm_operand_slot *pcVar3;
  c1_asm_operand_slot *slot_00;
  
  asm_report_operand_error(0x1a5,operand_count);
  while( true ) {
    pcVar2 = slot->record;
    if (pcVar2->index == esp_code) {
      if ((pcVar2->seg_scale & 0xc0) == 0) {
        if (pcVar2->base == esp_code) {
          asm_report_operand_error(0x1af,operand_count);
        }
        else {
          pcVar2->index = pcVar2->base;
          slot->record->base = esp_code;
        }
      }
      else {
        asm_report_operand_error(0x1af,operand_count);
      }
    }
    bVar1 = slot->record->seg_scale;
    slot->record->seg_scale = ((byte)g_asm_registers[bVar1 & 0x3f] ^ bVar1) & 0x3f ^ bVar1;
    slot->record->index = (c1_u8)g_asm_registers[slot->record->index];
    pcVar2 = slot->record;
    bVar1 = pcVar2->base;
    if ((pcVar2->kind & 0x20) == 0x20) {
      pcVar2->base = bVar1 + 0x28;
    }
    else if (bVar1 == 0) {
      if ((pcVar2->seg_scale & 0xc0) == 0) {
        pcVar2->base = pcVar2->index;
        slot->record->index = '?';
      }
      else {
        pcVar2->base = '?';
      }
    }
    else if ((g_asm_registers[bVar1] & 0x80c0) == 0x8080) {
      pcVar2->base = (char)g_asm_registers[bVar1] + '(';
    }
    else {
      pcVar2->base = (c1_u8)g_asm_registers[bVar1];
    }
    operand_count = operand_count + 1;
    slot_00 = slot + 1;
    if (g_asm_operand_index <= operand_count) break;
    pcVar3 = slot + 1;
    slot = slot_00;
    if (((pcVar3->size_given & 1) != 0) &&
       (g_asm_mode_class[g_asm_kind_mode[slot_00->record->kind & 0x1f]] == 1)) {
      asm_encode_operand_registers_fragment(esp_code,operand_count,slot_00);
      return;
    }
  }
  return;
}

