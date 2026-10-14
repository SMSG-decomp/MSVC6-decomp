int __fastcall merge_tails_operand_compare(c2_operand *a,c2_operand *b,int bind)

{
  byte bVar1;
  uint16_t b_00;
  uint16_t a_00;
  c2_symbol *a_01;
  c2_symbol *b_01;
  int iVar2;
  
  if (a == b) {
    return 0;
  }
  if (a == (c2_operand *)0x0) {
    return -1;
  }
  if (b == (c2_operand *)0x0) {
    return 1;
  }
  if (((((1 << (a->kind & 0x1f) & 6U) != 0) && (a_01 = a->sym, a_01->def != (c2_tuple *)0x0)) &&
      (bVar1 = b->kind, (1 << (bVar1 & 0x1f) & 6U) != 0)) &&
     (b_01 = b->sym, b_01->def != (c2_tuple *)0x0)) {
    if (a->kind != bVar1) {
      return (-(uint)(a->kind < bVar1) & 0xfffffffe) + 1;
    }
    b_00 = b->type;
    a_00 = a->type;
    iVar2 = types_compatible(a_00,b_00);
    if (iVar2 == 0) {
      return (-(uint)(a_00 < b_00) & 0xfffffffe) + 1;
    }
    if (bind != 0) {
      (b_01->u28).free_next = a_01;
      (a_01->u28).free_next = a_01;
      return 0;
    }
    iVar2 = symbol_compare(a_01,b_01);
    return iVar2;
  }
  iVar2 = operand_compare(a,b);
  return iVar2;
}

