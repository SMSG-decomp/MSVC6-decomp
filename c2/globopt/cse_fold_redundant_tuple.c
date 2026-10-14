c2_tuple * __fastcall cse_fold_redundant_tuple(c2_tuple *t,c2_block *block,c2_function *fn)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  uint32_t uVar3;
  int iVar4;
  c2_tuple *pcVar5;
  c2_operand *local_4;
  
  uVar3 = t->op;
  local_4 = (c2_operand *)t;
  if (uVar3 == 0x15b) {
    uVar3 = is_store_of_same_loaded_value(t,t->src);
    if (uVar3 == 0) {
      return t;
    }
    iVar4 = node_has_side_effects((c2_node *)t);
    if (iVar4 != 0) {
      return t;
    }
    if ((((t->type & 0xf000) == 0x5000) && ((1 << (t->dst->kind & 0x1f) & 6U) != 0)) &&
       (t->dst->sym->cls == '\x03')) {
      return t;
    }
  }
  else {
    if (uVar3 == 0x17d) {
LAB_1074c8fe:
      if ((t->u14).expr == (c2_symbol *)0x0) {
        return t;
      }
      uVar3 = evaluate_compare_from_available(g_cur_avail_set,(t->u14).expr);
      if (uVar3 == 1) {
        iVar4 = 1;
      }
      else {
        if (uVar3 != 2) {
          return t;
        }
        iVar4 = 0;
      }
      if (t->op == 399) {
        pcVar5 = t;
        t = t->src->sym->def;
      }
      else {
        pcVar5 = find_next_use_of_dst(t,&local_4);
      }
      pcVar5 = cse_fold_known_branch(t,pcVar5,local_4,block,fn,iVar4);
      return pcVar5;
    }
    if (uVar3 == 399) {
      if (((((1 << (t->dst->kind & 0x1f) & 6U) == 0) ||
           (pcVar2 = t->dst->sym, (pcVar2->u18).expr == (c2_cse_expr *)0x0)) ||
          (pcVar2->def != (c2_tuple *)0x0)) ||
         (uVar3 = bitset_test(g_cur_avail_set,pcVar2->id), uVar3 == 0)) goto LAB_1074c8fe;
      iVar4 = node_has_side_effects((c2_node *)t);
      if (iVar4 != 0) {
        return t;
      }
    }
    else {
      pcVar1 = t->dst;
      if (((pcVar1 == (c2_operand *)0x0) || ((1 << (pcVar1->kind & 0x1f) & 6U) == 0)) ||
         ((pcVar2 = pcVar1->sym, (pcVar2->u18).expr == (c2_cse_expr *)0x0 ||
          ((pcVar2->def != (c2_tuple *)0x0 ||
           (uVar3 = bitset_test(g_cur_avail_set,pcVar2->id), uVar3 == 0)))))) {
        return t;
      }
      iVar4 = node_has_side_effects((c2_node *)t);
      if (iVar4 != 0) {
        return t;
      }
      if (t->flags13 == '\x03') {
        t->flags = t->flags | 0x10;
        if (g_pending_tuples == (c2_list_cell *)0x0) {
          return (c2_tuple *)0x0;
        }
        if ((g_pending_tuples->u04).tuple != t) {
          return (c2_tuple *)0x0;
        }
        return t;
      }
    }
  }
  tuple_delete(t);
  return (c2_tuple *)0x0;
}

