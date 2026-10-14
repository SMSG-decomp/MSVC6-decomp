c2_tuple * __fastcall try_hoist_invariant_tuple(c2_tuple *t,c2_loop *loop)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  uint32_t uVar4;
  uint uVar5;
  uint32_t uVar6;
  int iVar7;
  c2_symbol *local_8;
  
  pcVar1 = t->dst;
  if (t->op == 0x15b) {
    uVar5 = 1 << (pcVar1->kind & 0x1f) & 6;
    if ((uVar5 != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) {
      return t;
    }
    local_8 = (t->u14).expr;
    if (uVar5 == 0) {
      return t;
    }
    uVar6 = hoist_target_live_on_entry(pcVar1->sym,g_preheader_live_out,g_preheader_must_set);
    if (uVar6 != 0) {
      return t;
    }
  }
  else {
    if (pcVar1 == (c2_operand *)0x0) {
      return t;
    }
    if ((1 << (pcVar1->kind & 0x1f) & 6U) == 0) {
      return t;
    }
    local_8 = pcVar1->sym;
    if ((local_8->u18).expr == (c2_cse_expr *)0x0) {
      return t;
    }
  }
  uVar6 = local_8->id;
  uVar4 = bitset_test(g_cur_avail_set,uVar6);
  if (((uVar4 != 0) && (iVar7 = node_has_side_effects((c2_node *)t), iVar7 == 0)) &&
     ((((t->op != 0x16d && (t->op != 0x16e)) ||
       ((t->next->op != 0x15b || (iVar7 = operand_compare(t->dst,t->next->src), iVar7 != 0)))) ||
      ((iVar7 = operand_compare(t->next->dst,t->src), iVar7 != 0 &&
       (iVar7 = operand_compare(t->next->dst,t->src->next), iVar7 != 0)))))) {
    if ((t->kind == '\x12') || (t->kind == '\x10')) {
      for (pcVar2 = ((local_8->u18).expr)->operands; pcVar2 != (c2_operand *)0x0;
          pcVar2 = pcVar2->next) {
        if ((((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
            ((pcVar2->sym->u18).expr != (c2_cse_expr *)0x0)) &&
           (uVar4 = bitset_test(g_preheader_avail_exprs,pcVar2->sym->id), uVar4 == 0)) {
          return t;
        }
      }
    }
    else {
      for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
            ((pcVar2->sym->u18).expr != (c2_cse_expr *)0x0)) &&
           (uVar4 = bitset_test(g_preheader_avail_exprs,pcVar2->sym->id), uVar4 == 0)) {
          return t;
        }
      }
    }
    if (t->flags13 == '\x03') {
      t = (c2_tuple *)node_clone((c2_node *)t);
    }
    else {
      tuple_unlink(t);
    }
    if (t->kind == '\x12') {
      for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
           (pcVar3 = pcVar2->sym->def, pcVar3 != (c2_tuple *)0x0)) {
          tuple_unlink(pcVar3);
          tuple_insert_before(g_preheader_insert_point,pcVar2->sym->def);
        }
      }
    }
    else if (t->kind == '\x10') {
      for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
           (pcVar3 = pcVar2->sym->def, pcVar3 != (c2_tuple *)0x0)) {
          tuple_unlink(pcVar3);
          tuple_insert_before(g_preheader_insert_point,pcVar2->sym->def);
        }
      }
    }
    tuple_insert_before(g_preheader_insert_point,t);
    avail_gen_expression(local_8);
    bitset_set(loop->first->set50,uVar6);
    bitset_set(g_preheader_avail_exprs,uVar6);
    bitset_set(g_hoisted_exprs,uVar6);
    if (((t->op == 0x15b) && ((1 << (pcVar1->kind & 0x1f) & 6U) != 0)) &&
       ((pcVar1->sym->u18).expr != (c2_cse_expr *)0x0)) {
      uVar6 = t->dst->sym->id;
      bitset_set(loop->first->set50,uVar6);
      bitset_set(g_preheader_avail_exprs,uVar6);
      bitset_set(g_hoisted_exprs,uVar6);
    }
    return (c2_tuple *)0x0;
  }
  return t;
}

