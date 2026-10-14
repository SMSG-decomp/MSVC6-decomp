c2_operand * __fastcall accept_iv_init_difference(c2_tuple *t)

{
  uint8_t *puVar1;
  c2_symbol *chain;
  uint32_t uVar2;
  c2_operand *pcVar3;
  uint32_t op;
  
  if (t->op == 0x15b) {
    uVar2 = is_loop_invariant_operand(t->src);
    if (uVar2 != 0) {
      return t->src;
    }
  }
  else if (t->op == 0x16e) {
    uVar2 = is_loop_invariant_operand(t->src);
    if (uVar2 != 0) {
      uVar2 = is_loop_invariant_operand(t->src->next);
      if (uVar2 != 0) {
        if (t->src->next->kind == '\a') {
          op = 0x16d;
          t->op = 0x16d;
          pcVar3 = t->src->next;
          uVar2 = (pcVar3->u18).lo;
          (pcVar3->u18).lo = -uVar2;
          pcVar3->tag = -(pcVar3->tag + (uint)(uVar2 != 0));
        }
        else {
          op = 0x16e;
        }
        chain = t->dst->sym;
        pcVar3 = operand_new_cse_sym(op,t->type,t->src,t->src->next);
        symbol_free_chain(chain);
        pcVar3 = tuple_replace_dst(t,t->dst,pcVar3);
        tuple_unlink(t);
        tuple_insert_before(g_preheader_insert_point,t);
        uVar2 = pcVar3->sym->id;
        puVar1 = &(pcVar3->sym->u30).sizeopt.width_facts;
        *puVar1 = *puVar1 | 6;
        bitset_set(g_invariant_expr_syms,uVar2);
        bitset_set(g_preheader_avail_exprs,uVar2);
        return pcVar3;
      }
    }
  }
  return (c2_operand *)0x0;
}

