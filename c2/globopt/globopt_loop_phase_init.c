void globopt_loop_phase_init(void)

{
  uint16_t *puVar1;
  c2_symbol *sym;
  c2_symbol_chunk *chunk;
  
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    sym = chunk->syms;
    if (sym < chunk->cursor) {
      do {
        if (sym->cls != '\x10') {
          puVar1 = &(sym->u30).globopt.marks;
          *puVar1 = *puVar1 & 0xfff9;
          sym->uses = (c2_list_cell *)0x0;
          sym->defs = (c2_list_cell *)0x0;
        }
        sym = sym + 1;
      } while (sym < chunk->cursor);
    }
  }
  g_iv_syms = sparse_set_alloc_default();
  g_narrow_iv_syms = sparse_set_alloc_default();
  g_invariant_expr_syms = sparse_set_alloc_default();
  g_iv_excluded_syms = sparse_set_alloc_default();
  g_iv_partial_alias_syms = sparse_set_alloc_default();
  g_iv_spare_syms = sparse_set_alloc_default();
  g_iv_syms_prev = sparse_set_alloc_default();
  g_sr_seen_exprs = sparse_set_alloc_default();
  g_sr_init_exprs = sparse_set_alloc_default();
  g_iv_assigned_exprs = sparse_set_alloc_default();
  g_aggregate_member_syms = sparse_set_alloc_default();
  return;
}

