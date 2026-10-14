short * __cdecl asm_check_register_3(short *operand)

{
  c1_u8 *pcVar1;
  int iVar2;
  
  if ((g_asm_current_operand->record->kind & 1) == 0) {
    if (*operand == 3) {
      iVar2 = asm_operand_description_id();
      diag_error(0x194,g_last_name,iVar2);
    }
    else {
      diag_error(0x19f);
    }
    g_asm_current_operand->record->sym = g_builtin_label_1;
    *operand = 2;
  }
  pcVar1 = &g_asm_current_operand->record->kind;
  *pcVar1 = *pcVar1 & 0xe8;
  pcVar1 = &g_asm_current_operand->record->kind;
  *pcVar1 = *pcVar1 | 3;
  g_asm_current_operand->size_class = '\x02';
  return operand;
}

