void __cdecl asm_encode_operand_registers(void)

{
  byte bVar1;
  c1_asm_operand *pcVar2;
  c1_asm_operand_slot *slot;
  int operand_count;
  
  operand_count = 0;
  if (0 < g_asm_operand_index) {
    slot = g_asm_operand_slots;
    do {
      if (((slot->size_given & 1) != 0) &&
         (g_asm_mode_class[g_asm_kind_mode[slot->record->kind & 0x1f]] == 1)) {
        asm_encode_operand_registers_fragment('\x05',operand_count,slot);
        return;
      }
      pcVar2 = slot->record;
      if (pcVar2->index == '\x05') {
        if ((pcVar2->seg_scale & 0xc0) == 0) {
          if (pcVar2->base == '\x05') {
            asm_report_operand_error(0x1af,operand_count);
          }
          else {
            pcVar2->index = pcVar2->base;
            slot->record->base = '\x05';
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
      slot = slot + 1;
    } while (operand_count < g_asm_operand_index);
  }
  return;
}

