short * __cdecl asm_check_segment_override(short seg_reg,short *operand)

{
  c1_u8 *pcVar1;
  byte bVar2;
  int iVar3;
  
  if ((g_asm_registers[seg_reg] & 0xc0) == 0x40) {
    bVar2 = g_asm_current_operand->record->seg_scale;
    if ((((bVar2 & 0x3f) == 0) && (g_asm_in_brackets == 0)) && (*operand != 3)) {
      g_asm_current_operand->record->seg_scale = (bVar2 ^ (byte)seg_reg) & 0x3f ^ bVar2;
      pcVar1 = &g_asm_current_operand->record->kind;
      *pcVar1 = *pcVar1 & 0xef;
      pcVar1 = &g_asm_current_operand->record->kind;
      *pcVar1 = *pcVar1 | 0x10;
      return operand;
    }
  }
  iVar3 = asm_operand_description_id();
  diag_error(0x1a6,iVar3);
  return operand;
}

