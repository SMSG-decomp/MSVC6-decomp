void __fastcall cse_tuple(c2_tuple *t,c2_block *block,c2_function *fn)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_list_cell *pcVar3;
  c2_function *fn_00;
  int iVar4;
  uint32_t uVar5;
  c2_tuple *br;
  c2_tuple *pcVar6;
  
  fn_00 = fn;
  if ((g_cse_full_mode == 0) && ((g_cse_fold_compares == 0 || (t->op != 0x17d)))) goto LAB_1070e3c5;
  uVar5 = t->op;
  if (uVar5 == 0x15b) {
    uVar5 = is_store_of_same_loaded_value(t,t->src);
    if (((uVar5 != 0) && (iVar4 = node_has_side_effects((c2_node *)t), iVar4 == 0)) &&
       (((t->type & 0xf000) != 0x5000 ||
        (((1 << (t->dst->kind & 0x1f) & 6U) == 0 || (t->dst->sym->cls != '\x03')))))) {
      tuple_delete(t);
      return;
    }
  }
  else if (uVar5 == 0x17d) {
LAB_1070e4ca:
    if ((t->u14).expr != (c2_symbol *)0x0) {
      uVar5 = evaluate_compare_from_available(g_cur_avail_set,(t->u14).expr);
      if (uVar5 == 1) {
        iVar4 = 1;
      }
      else {
        if (uVar5 != 2) goto LAB_1070e455;
        iVar4 = 0;
      }
      if (t->op == 399) {
        pcVar6 = t->src->sym->def;
        br = t;
      }
      else {
        br = find_next_use_of_dst(t,(c2_operand **)&fn);
        pcVar6 = t;
      }
      t = cse_fold_known_branch(pcVar6,br,(c2_operand *)fn,block,fn_00,iVar4);
    }
  }
  else if (uVar5 == 399) {
    if ((((1 << (t->dst->kind & 0x1f) & 6U) == 0) ||
        (pcVar2 = t->dst->sym, (pcVar2->u18).expr == (c2_cse_expr *)0x0)) ||
       ((pcVar2->def != (c2_tuple *)0x0 ||
        (uVar5 = bitset_test(g_cur_avail_set,pcVar2->id), uVar5 == 0)))) goto LAB_1070e4ca;
    iVar4 = node_has_side_effects((c2_node *)t);
    if (iVar4 == 0) {
LAB_1070e4b5:
      tuple_delete(t);
      return;
    }
  }
  else {
    pcVar1 = t->dst;
    if (((((pcVar1 != (c2_operand *)0x0) && ((1 << (pcVar1->kind & 0x1f) & 6U) != 0)) &&
         (pcVar2 = pcVar1->sym, (pcVar2->u18).expr != (c2_cse_expr *)0x0)) &&
        ((pcVar2->def == (c2_tuple *)0x0 &&
         (uVar5 = bitset_test(g_cur_avail_set,pcVar2->id), uVar5 != 0)))) &&
       (iVar4 = node_has_side_effects((c2_node *)t), iVar4 == 0)) {
      if (t->flags13 != '\x03') goto LAB_1070e4b5;
      t->flags = t->flags | 0x10;
      if (g_pending_tuples == (c2_list_cell *)0x0) {
        return;
      }
      if ((g_pending_tuples->u04).tuple != t) {
        return;
      }
    }
  }
LAB_1070e455:
  if (t == (c2_tuple *)0x0) {
    return;
  }
  cse_propagate_copy_equivalences(t);
LAB_1070e3c5:
  iVar4 = cse_replace_operands(t);
  if ((iVar4 == 0) &&
     ((g_pending_tuples == (c2_list_cell *)0x0 || ((g_pending_tuples->u04).tuple != t)))) {
    if (t->op == 0x17d) {
      pcVar6 = simplify_tuple(t,block,fn_00);
      if (pcVar6 == (c2_tuple *)0x0) {
        return;
      }
      enter_tuple_in_expression_table(pcVar6,0);
      avail_transfer_tuple(pcVar6);
      return;
    }
  }
  else {
    if ((g_pending_tuples != (c2_list_cell *)0x0) &&
       (((g_pending_tuples->u04).tuple == t && (g_pending_tuples != (c2_list_cell *)0x0)))) {
      pcVar3 = g_pending_tuples->next;
      g_pending_tuples->next = g_list_node_free;
      g_list_node_free = g_pending_tuples;
      g_pending_tuples = pcVar3;
    }
    t = simplify_tuple(t,block,fn_00);
    if (t == (c2_tuple *)0x0) {
      return;
    }
    enter_tuple_in_expression_table(t,0);
    if (g_cse_full_mode == 0) {
      if ((g_cse_fold_compares != 0) && (t->op == 0x17d)) {
        cse_tuple_part(t,block,fn_00);
        return;
      }
    }
    else {
      t = cse_fold_redundant_tuple(t,block,fn_00);
      if (t == (c2_tuple *)0x0) {
        return;
      }
    }
  }
  avail_transfer_tuple(t);
  return;
}

