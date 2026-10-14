c2_tuple * __fastcall factor_common_terms(c2_tuple *t,c2_tuple *parent)

{
  c2_operand_u18 cVar1;
  c2_tuple *pcVar2;
  int iVar3;
  c2_const_operand *op;
  c2_operand *pcVar4;
  uint8_t uVar5;
  c2_tuple *child;
  uint64_t uVar6;
  c2_tuple *result;
  
  result = t;
  switch(t->op) {
  case 0x16d:
    for (pcVar4 = t->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
      if ((pcVar4->op == 0x171) &&
         (iVar3 = shift_by_constant_to_mul((c2_tuple *)pcVar4), iVar3 != 0)) {
        refresh_node_cost_shallow((c2_tuple *)pcVar4);
      }
    }
    iVar3 = factor_out_common_operand(t,0x16f,0x161);
    if (iVar3 != 0) goto LAB_10708ea7;
    iVar3 = fold_bitfield_merge(t);
    break;
  default:
    goto switchD_10708e60_caseD_16e;
  case 0x172:
    iVar3 = factor_out_common_operand(t,0x173,0x145);
    if (iVar3 != 0) {
      pcVar2 = simplify_node_algebraic(t,parent);
      return pcVar2;
    }
    iVar3 = has_operand_with_opcode(t,0x171,0x145);
    if ((iVar3 != 0) && (iVar3 = factor_out_common_operand(t,0x171,0x145), iVar3 != 0)) {
      pcVar2 = simplify_node_algebraic(t,parent);
      return pcVar2;
    }
    iVar3 = has_operand_with_opcode(t,0x177,0x145);
    if (iVar3 == 0) {
      return t;
    }
    iVar3 = factor_out_common_operand(t,0x177,0x145);
    break;
  case 0x173:
  case 0x174:
    iVar3 = factor_out_common_operand(t,0x172,0x145);
    if (((iVar3 != 0) ||
        ((iVar3 = has_operand_with_opcode(t,0x171,0x145), iVar3 != 0 &&
         (iVar3 = factor_out_common_operand(t,0x171,0x145), iVar3 != 0)))) ||
       ((iVar3 = has_operand_with_opcode(t,0x177,0x145), iVar3 != 0 &&
        (iVar3 = factor_out_common_operand(t,0x177,0x145), iVar3 != 0)))) goto LAB_10708ea7;
    iVar3 = fold_bitfield_merge(t);
    break;
  case 0x17d:
    if (parent == (c2_tuple *)0x0) {
      uVar5 = (uint8_t)g_simplify_context_tuple->type;
    }
    else {
      uVar5 = (parent->u20).cc;
    }
    iVar3 = has_operand_with_opcode(t,0x177,0x145);
    if (((iVar3 != 0) && (iVar3 = factor_combine_constant_terms(t,0x177,0x145), iVar3 != 0)) ||
       (((((t->type & 0xf000) != 0x1000 || ((uVar5 == '\x01' || (uVar5 == '\x02')))) &&
         (iVar3 = has_operand_with_opcode(t,0x171,0x145), iVar3 != 0)) &&
        (iVar3 = factor_combine_constant_terms(t,0x171,0x145), iVar3 != 0)))) {
      child = (c2_tuple *)t->src;
      if (((c2_operand *)child)->next != (c2_operand *)0x0) {
        node_free((c2_node *)((c2_operand *)child)->next);
        child = (c2_tuple *)t->src;
        ((c2_operand *)child)->next = (c2_operand *)0x0;
      }
      result = (c2_tuple *)child->src;
      cVar1 = ((c2_operand *)result)->u18;
      (((c2_operand *)result)->u18).reg = (c2_symbol *)0x0;
      t->src = (c2_operand *)cVar1;
      if (parent != (c2_tuple *)0x0) {
        tuple_insert_src_after(parent,(c2_operand *)t,(c2_operand *)child);
        tuple_detach_src((c2_node *)parent,(c2_operand *)t);
      }
      tuple_replace_src(child,(c2_operand *)result,(c2_operand *)t);
      uVar6 = shift_mask_constant(child);
      pcVar4 = child->src->next;
      pcVar4->u18 = (c2_operand_u18)(int)uVar6;
      pcVar4->tag = (int)(uVar6 >> 0x20);
      child->src->next->type = child->type;
      child->op = 0x172;
      result = child;
      distribute_constant_over_op(&result,0x17d,parent);
      return result;
    }
    if ((((uVar5 == '\x01') || (uVar5 == '\x02')) && (t->src->op == 0x172)) &&
       ((t->src->next->op == 0x172 &&
        (iVar3 = factor_combine_constant_terms(t,0x172,0x145), iVar3 != 0)))) {
      op = operand_new_intconst(t->type,0,0);
      tuple_append_src(t,op);
      child = (c2_tuple *)((t->src->u18).reg)->fe;
      child->op = 0x174;
      pcVar4 = operand_new_temp(child->type);
      tuple_replace_dst(child,child->dst,pcVar4);
      symbol_mark_overlapping_parts(child->dst->sym,child);
    }
    goto switchD_10708e60_caseD_16e;
  }
  if (iVar3 != 0) {
LAB_10708ea7:
    pcVar2 = simplify_node_algebraic(t,parent);
    return pcVar2;
  }
switchD_10708e60_caseD_16e:
  return t;
}

