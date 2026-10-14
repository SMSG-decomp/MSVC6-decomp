void __cdecl c1xx_cleanup(void)

{
  __3_YAXPAX_Z(g_emitter_suspend);
  text_buffers_free();
  arenas_free_all();
  token_buffers_free();
  block_lists_free();
  mem_free(g_pp_cond_states);
  return;
}

