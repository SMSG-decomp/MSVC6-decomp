c2_operand * cse_claim_key_operands(void)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *op;
  int iVar3;
  c2_operand *pcVar4;
  
  pcVar1 = operand_claim(g_expr_operand_scratch[0]);
  if (g_expr_operand_scratch[1] != (c2_operand *)0x0) {
    iVar3 = 0x10799624;
    op = g_expr_operand_scratch[1];
    pcVar4 = pcVar1;
    do {
      pcVar2 = operand_claim(op);
      op = *(c2_operand **)(iVar3 + 4);
      iVar3 = iVar3 + 4;
      pcVar4->next = pcVar2;
      pcVar4 = pcVar2;
    } while (op != (c2_operand *)0x0);
    return pcVar1;
  }
  return pcVar1;
}

