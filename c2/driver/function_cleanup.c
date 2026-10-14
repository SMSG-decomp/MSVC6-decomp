void function_cleanup(void)

{
  if (g_pdb_il_mode != 0) {
    function_cleanup_drop_unknown_inits();
  }
  function_cleanup_free_inits();
  clear_symbol_storage_links();
  function_cleanup_reset();
  arena_reset(5);
  arena_reset(0xc);
  arena_reset(8);
  arena_reset(1);
  arena_reset(6);
  arena_reset(4);
  g_eh_alloca_markers = (c2_eh_alloca_marker *)0x0;
  return;
}

