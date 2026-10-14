int * __cdecl asm_operand_reset(int operand)

{
  c1_asm_operand_slot *pcVar1;
  
  g_asm_member_class = (c1_symbol *)0x0;
  pcVar1 = g_asm_operand_slots + operand;
  g_asm_operand_slots[operand].size_class = '\x0f';
  g_asm_operand_slots[operand].size_given = '\0';
  pcVar1->record = g_asm_operand_records + operand;
  g_asm_operand_records[operand].sym = (c1_symbol *)0x0;
  pcVar1->record->value = 0;
  pcVar1->record->kind = '\0';
  pcVar1->record->seg_scale = pcVar1->record->seg_scale & 0xc0;
  pcVar1->record->base = '\0';
  pcVar1->record->index = '\0';
  pcVar1->record->seg_scale = pcVar1->record->seg_scale & 0x3f;
  g_asm_operand_slots[operand].ref_symbol = (c1_symbol *)0x0;
  g_asm_operand_slots[operand].frame_symbol = (c1_symbol *)0x0;
  return (int *)pcVar1;
}

