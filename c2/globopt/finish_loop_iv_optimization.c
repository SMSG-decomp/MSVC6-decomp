void finish_loop_iv_optimization(void)

{
  uint16_t *puVar1;
  uint32_t uVar2;
  c2_symbol *pcVar3;
  
  drop_iv_op_expressions();
  uVar2 = bitset_iter_next(g_invariant_expr_syms);
  while (uVar2 != 0xffffffff) {
    pcVar3 = symbol_by_id(uVar2);
    puVar1 = &(pcVar3->u30).globopt.marks;
    *puVar1 = *puVar1 & 0xfff9;
    uVar2 = bitset_iter_next((c2_bitset *)0x0);
  }
  uVar2 = bitset_iter_next(g_iv_syms);
  while (uVar2 != 0xffffffff) {
    pcVar3 = symbol_by_id(uVar2);
    pcVar3->uses = (c2_list_cell *)0x0;
    pcVar3->defs = (c2_list_cell *)0x0;
    uVar2 = bitset_iter_next((c2_bitset *)0x0);
  }
  bitset_clear_all(g_iv_syms);
  bitset_clear_all(g_narrow_iv_syms);
  bitset_clear_all(g_invariant_expr_syms);
  bitset_clear_all(g_iv_spare_syms);
  bitset_clear_all(g_iv_syms_prev);
  bitset_clear_all(g_iv_excluded_syms);
  bitset_clear_all(g_iv_partial_alias_syms);
  bitset_clear_all(g_sr_seen_exprs);
  bitset_clear_all(g_sr_init_exprs);
  bitset_clear_all(g_iv_assigned_exprs);
  bitset_clear_all(g_aggregate_member_syms);
  reset_list_node_pool();
  if (g_trip_counter_operand != (c2_operand *)0x0) {
    node_free((c2_node *)g_trip_counter_operand);
    g_trip_counter_operand = (c2_operand *)0x0;
  }
  free_pending_tuple_list();
  node_free((c2_node *)g_iv_scratch_list_head);
  node_free((c2_node *)g_iv_scratch_tail);
  g_iv_scratch_list_head = (c2_tuple *)0x0;
  g_iv_scratch_tail = (c2_tuple *)0x0;
  return;
}

