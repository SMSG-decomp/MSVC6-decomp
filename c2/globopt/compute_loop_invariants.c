void __fastcall compute_loop_invariants(c2_function *fn)

{
  c2_loop *loop;
  
  if (fn->loops != (c2_loop *)0x0) {
    g_trackable_syms = make_trackable_symbol_set(4);
    g_loop_killed_syms = bitset_new(4);
    g_alias_class_expanded = bitset_new(4);
    clear_block_visited_flags(fn);
    for (loop = fn->loops; loop != (c2_loop *)0x0; loop = loop->next) {
      mark_loop_invariants(loop);
      bitset_clear_all(g_loop_killed_syms);
      bitset_clear_all(g_alias_class_expanded);
    }
    arena_reset(4);
  }
  return;
}

