void globopt_loop_phase_free(void)

{
  bitset_free(g_iv_syms);
  bitset_free(g_narrow_iv_syms);
  bitset_free(g_invariant_expr_syms);
  bitset_free(g_iv_spare_syms);
  bitset_free(g_iv_syms_prev);
  bitset_free(g_iv_excluded_syms);
  bitset_free(g_iv_partial_alias_syms);
  bitset_free(g_sr_seen_exprs);
  bitset_free(g_sr_init_exprs);
  bitset_free(g_iv_assigned_exprs);
  bitset_free(g_aggregate_member_syms);
  return;
}

