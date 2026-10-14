void symbol_pools_reset(void)

{
  c2_bitset *bs;
  
  g_symbol_chunk_index = arena_alloc(1,4000);
  g_symbol_chunk_index_end = g_symbol_chunk_index + 1000;
  g_next_symbol_id = 0;
  g_symbol_chunks = (c2_symbol_chunk *)0x0;
  g_symbol_chunk_tail = (c2_symbol_chunk *)0x0;
  g_symbol_chunk_index_cursor = g_symbol_chunk_index;
  g_pool_b_symbol_chunk = symbol_chunk_new();
  g_pool_c_symbol_chunk = symbol_chunk_new();
  g_pool_a_symbol_chunk = symbol_chunk_new();
  g_pool_d_symbol_chunk = symbol_chunk_new();
  g_pool_e_symbol_chunk = (c2_symbol_chunk *)0x0;
  g_temp_symbol_free = (c2_symbol *)0x0;
  g_local_symbol_free = (c2_symbol *)0x0;
  g_referenced_symbol_list = (c2_list_cell *)0x0;
  g_global_symbol_ids = bitset_new(1);
  g_local_symbol_ids = bitset_new(1);
  g_symbol_id0_record = symbol_alloc('\x04');
  bs = g_local_symbol_ids;
  g_symbol_id0_record->cls = '\x10';
  bitset_clear_all(bs);
  return;
}

