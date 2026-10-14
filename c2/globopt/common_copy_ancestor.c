c2_operand * __fastcall common_copy_ancestor(c2_operand *a,c2_operand *b)

{
  c2_symbol *pcVar1;
  c2_cse_expr *pcVar2;
  c2_bitset *bs;
  c2_bitset *bs_00;
  uint32_t uVar3;
  
  bs = sparse_set_alloc_default();
  for (pcVar1 = a->sym; pcVar1 != (c2_symbol *)0x0; pcVar1 = ((pcVar1->u18).expr)->operands->sym) {
    bitset_set(bs,pcVar1->id);
    if ((pcVar1->u18).expr == (c2_cse_expr *)0x0) break;
  }
  bs_00 = sparse_set_alloc_default();
  for (pcVar1 = b->sym; pcVar1 != (c2_symbol *)0x0; pcVar1 = ((pcVar1->u18).expr)->operands->sym) {
    bitset_set(bs_00,pcVar1->id);
    if ((pcVar1->u18).expr == (c2_cse_expr *)0x0) break;
  }
  bitset_and(bs,bs_00);
  do {
    if (a == (c2_operand *)0x0) {
LAB_107616c0:
      bitset_free(bs);
      bitset_free(bs_00);
      return a;
    }
    pcVar1 = a->sym;
    uVar3 = bitset_test(bs,pcVar1->id);
    if (uVar3 != 0) goto LAB_107616c0;
    pcVar2 = (pcVar1->u18).expr;
    if (pcVar2 == (c2_cse_expr *)0x0) {
      a = (c2_operand *)0x0;
      goto LAB_107616c0;
    }
    a = pcVar2->operands;
  } while( true );
}

