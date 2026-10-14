void __cdecl asm_check_operand_count(void)

{
  int iVar1;
  
  iVar1 = asm_operand_count_valid();
  if (iVar1 == 0) {
    diag_error(0x19e);
    return;
  }
  if (0 < g_asm_operand_index) {
    iVar1 = asm_operand_kinds_valid();
    if (iVar1 == 0) {
      diag_error(0x19f);
      return;
    }
  }
  asm_finalize_instruction();
  asm_build_instruction_record();
  il_emit_pragma_or_segment_record(0x16);
  return;
}

