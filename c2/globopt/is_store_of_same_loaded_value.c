uint32_t __fastcall is_store_of_same_loaded_value(c2_tuple *t,c2_operand *opnd)

{
  c2_symbol *pcVar1;
  c2_cse_expr *pcVar2;
  uint32_t uVar3;
  int iVar4;
  
  if ((((t->dst->kind == '\x06') && ((1 << (opnd->kind & 0x1f) & 6U) != 0)) &&
      (pcVar1 = opnd->sym, (pcVar1->u18).expr != (c2_cse_expr *)0x0)) &&
     (pcVar1->def == (c2_tuple *)0x0)) {
    uVar3 = bitset_test(g_cur_avail_set,pcVar1->id);
    if ((uVar3 != 0) && (pcVar2 = (opnd->sym->u18).expr, pcVar2->op == 0x15d)) {
      iVar4 = operand_compare(t->dst,pcVar2->operands);
      if (iVar4 == 0) {
        return 1;
      }
    }
  }
  return 0;
}

