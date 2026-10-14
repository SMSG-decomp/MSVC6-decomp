c1_asm_operand * __cdecl asm_operand_reset(int operand)

{
  c1_asm_operand *pcVar1;
  
  g_asm_member_struct = (void *)0x0;
  pcVar1 = g_asm_operands + operand;
  g_asm_operands[operand].size_class = '\x0f';
  g_asm_operands[operand].flags = '\0';
  pcVar1->expr = g_asm_exprs + operand;
  g_asm_exprs[operand].sym = (c1_symbol *)0x0;
  pcVar1->expr->disp = 0;
  pcVar1->expr->kind = '\0';
  pcVar1->expr->seg_scale = pcVar1->expr->seg_scale & 0xc0;
  pcVar1->expr->base = '\0';
  pcVar1->expr->index = '\0';
  pcVar1->expr->seg_scale = pcVar1->expr->seg_scale & 0x3f;
  g_asm_operands[operand].sym = (c1_symbol *)0x0;
  g_asm_operands[operand].frame_sym = (c1_symbol *)0x0;
  return pcVar1;
}

