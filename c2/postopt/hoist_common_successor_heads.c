int __fastcall hoist_common_successor_heads(c2_tuple *jcc)

{
  c2_tuple *label;
  bool bVar1;
  int iVar2;
  uint32_t uVar3;
  c2_tuple *b;
  c2_tuple *a;
  int local_c;
  
  bVar1 = false;
  label = *(c2_tuple **)&(jcc->src->sym->u30).globopt.marks;
  iVar2 = label_single_ref_no_fallthrough(label);
  if (iVar2 != 0) {
    local_c = 0;
    b = label;
    a = jcc;
    while( true ) {
      a = a->next;
      b = b->next;
      uVar3 = a->op;
      while (uVar3 == 0x1bc) {
        a = a->next;
        uVar3 = a->op;
      }
      if (b->op == 0x1bc) {
        bVar1 = true;
        do {
          b = b->next;
        } while (b->op == 0x1bc);
      }
      if ((((a->kind == '\x1a') || (b->kind == '\x1a')) || (b == jcc)) ||
         ((iVar2 = tuples_equal(a,b), iVar2 == 0 ||
          (uVar3 = tuple_clobbers_branch_operand(a,jcc), uVar3 != 0)))) break;
      local_c = local_c + 1;
    }
    if (local_c != 0) {
      if (bVar1) {
        cross_jump_fix_labels(label,b,jcc,a,0xffffffff,1);
      }
      tuple_move_before(a,jcc);
      tuple_range_free(label->next,b);
      return 1;
    }
  }
  return 0;
}

