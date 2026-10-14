c2_symbol_chunk * symbol_chunk_new(void)

{
  c2_symbol_chunk *pcVar1;
  c2_symbol_chunk *chunk;
  uint32_t index_len;
  c2_symbol_chunk **new_index;
  uint uVar2;
  int iVar3;
  c2_symbol_chunk **copy_src;
  c2_symbol_chunk **copy_dst;
  c2_symbol *sym;
  
  chunk = arena_alloc(1,0xa8c);
  sym = chunk->syms;
  chunk->next = (c2_symbol_chunk *)0x0;
  chunk->cursor = sym;
  chunk->end = (c2_symbol *)(chunk + 1);
  for (; sym < chunk + 1; sym = (c2_symbol *)&((c2_symbol_chunk *)sym)->syms[0].visit_stamp) {
    *(uint32_t *)&((c2_symbol_chunk *)sym)->syms[0].type = g_next_symbol_id;
    g_next_symbol_id = g_next_symbol_id + 1;
  }
  if (g_symbol_chunk_index_cursor == g_symbol_chunk_index_end) {
    index_len = (int)g_symbol_chunk_index_end - (int)g_symbol_chunk_index >> 2;
    new_index = arena_alloc(1,index_len * 8);
    copy_src = g_symbol_chunk_index;
    copy_dst = new_index;
    g_symbol_chunk_index = new_index;
    for (uVar2 = index_len & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *copy_dst = *copy_src;
      copy_src = copy_src + 1;
      copy_dst = copy_dst + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)copy_dst = *(undefined1 *)copy_src;
      copy_src = (c2_symbol_chunk **)((int)copy_src + 1);
      copy_dst = (c2_symbol_chunk **)((int)copy_dst + 1);
    }
    g_symbol_chunk_index_cursor = new_index + index_len;
    g_symbol_chunk_index_end = new_index + index_len * 2;
  }
  pcVar1 = chunk;
  if (g_symbol_chunks != (c2_symbol_chunk *)0x0) {
    g_symbol_chunk_tail->next = chunk;
    pcVar1 = g_symbol_chunks;
  }
  g_symbol_chunks = pcVar1;
  *g_symbol_chunk_index_cursor = chunk;
  g_symbol_chunk_tail = chunk;
  g_symbol_chunk_index_cursor = g_symbol_chunk_index_cursor + 1;
  return chunk;
}

