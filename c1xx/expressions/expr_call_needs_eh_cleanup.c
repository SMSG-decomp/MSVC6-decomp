char expr_call_needs_eh_cleanup(c1_node *expr)

{
  c1_u8 cVar1;
  int iVar2;
  c1_node **ppcVar3;
  c1_call_record cStack_28;
  
  if (expr->op != 'p') {
    return '\0';
  }
  cStack_28.expr = expr;
  ppcVar3 = &cStack_28.call;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppcVar3 = (c1_node *)0x0;
    ppcVar3 = ppcVar3 + 1;
  }
  if (expr != (c1_node *)0x0) {
    cVar1 = expr->op;
    cStack_28.call = expr;
    while (cVar1 != 'p') {
      cStack_28.call = (cStack_28.call)->left;
      cVar1 = (cStack_28.call)->op;
    }
  }
  if ((cStack_28.flags & 4) == 0) {
    expr_call_info_decode_callee(&cStack_28);
  }
  return (char)(((byte)~(cStack_28.function)->flags23 & 0x10) >> 4);
}

