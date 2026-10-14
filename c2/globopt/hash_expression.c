uint32_t __fastcall hash_expression(int op,uint16_t type)

{
  uint32_t uVar1;
  c2_operand *op_00;
  uint uVar2;
  c2_operand **ppcVar3;
  
  uVar2 = ((type & 0xfff) + op) % 0x65;
  if (g_expr_operand_scratch[0] != (c2_operand *)0x0) {
    ppcVar3 = g_expr_operand_scratch;
    op_00 = g_expr_operand_scratch[0];
    do {
      uVar1 = operand_hash_key(op_00);
      ppcVar3 = ppcVar3 + 1;
      uVar2 = (uVar1 + uVar2) % 0x65;
      op_00 = *ppcVar3;
    } while (op_00 != (c2_operand *)0x0);
    return uVar2;
  }
  return uVar2;
}

