int __fastcall operand_reaches_via_copies(c2_operand *a,c2_operand *b)

{
  c2_operand *a_00;
  int iVar1;
  uint uVar2;
  c2_symbol *src_sym;
  
  iVar1 = operand_compare(a,b);
  if (iVar1 == 0) {
    return 1;
  }
  uVar2 = 1 << (a->kind & 0x1f);
  if ((uVar2 & 6) == 0) {
    if ((uVar2 & 0x60) == 0) {
      return 0;
    }
    src_sym = (c2_symbol *)(a->u18).range;
  }
  else {
    src_sym = a->sym;
  }
  if ((src_sym->u18).expr != (c2_cse_expr *)0x0) {
    for (a_00 = ((src_sym->u18).expr)->operands; a_00 != (c2_operand *)0x0; a_00 = a_00->next) {
      iVar1 = operand_reaches_via_copies(a_00,b);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

