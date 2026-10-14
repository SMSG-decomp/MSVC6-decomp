void __cdecl asm_report_operand_error(int n,int operand_count)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_asm_operand_index;
  g_asm_operand_index = operand_count;
  iVar2 = asm_operand_description_id();
  diag_error((short)n,iVar2);
  g_asm_operand_index = iVar1;
  return;
}

