short * __cdecl asm_check_index_register(short op,short *left,short *right)

{
  c1_asm_operand *pcVar1;
  int iVar2;
  
  if (((g_asm_in_brackets == 0) || (*left != 1)) || (*right != 0)) {
    left = asm_check_constant_operand(op,left,right);
  }
  else {
    if ((g_asm_current_operand->record->seg_scale & 0xc0) != 0) {
      iVar2 = asm_operand_description_id();
      diag_error(0x1ae,iVar2);
    }
    iVar2 = asm_check_scale(*(uint *)(right + 2));
    g_asm_current_operand->record->seg_scale =
         g_asm_current_operand->record->seg_scale & 0x3f | (char)iVar2 << 6;
    pcVar1 = g_asm_current_operand->record;
    if ((pcVar1->seg_scale & 0xc0) != 0) {
      if (pcVar1->base == '\0') {
        iVar2 = asm_operand_description_id();
        diag_error(0x1af,iVar2);
      }
      else if (pcVar1->index == '\0') {
        pcVar1->index = pcVar1->base;
        g_asm_current_operand->record->base = '\0';
      }
    }
  }
  return left;
}

