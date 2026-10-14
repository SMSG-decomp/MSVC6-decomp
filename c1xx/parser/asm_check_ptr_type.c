void __cdecl asm_check_ptr_type(char size_code)

{
  c1_u8 *pcVar1;
  c1_asm_operand *pcVar2;
  int iVar3;
  
  if (((g_asm_current_operand->size_given & 1) != 0) ||
     (g_asm_current_operand->size_class = size_code, size_code == '\x0f')) {
    iVar3 = asm_operand_description_id();
    diag_error(0x198,iVar3);
  }
  if (g_asm_distance_operator == 0) {
    pcVar2 = g_asm_current_operand->record;
    if (pcVar2->sym == (c1_symbol *)0x0) {
      g_asm_current_operand->size_given = g_asm_current_operand->size_given | 1;
      return;
    }
    if ((pcVar2->sym == g_builtin_label_1) && ((pcVar2->seg_scale & 0x3f) == 0)) {
      pcVar2->seg_scale = pcVar2->seg_scale & 0xda | 0x1a;
    }
    g_asm_current_operand->record->kind = g_asm_current_operand->record->kind & 0xef;
    pcVar1 = &g_asm_current_operand->record->kind;
    *pcVar1 = *pcVar1 | 0x10;
  }
  g_asm_current_operand->size_given = g_asm_current_operand->size_given | 1;
  return;
}

