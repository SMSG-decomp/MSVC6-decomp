c2_symbol * __fastcall symbol_alloc(uint8_t kind)

{
  uint32_t uVar1;
  c2_bitset *pcVar2;
  c2_symbol_chunk *pcVar3;
  int iVar4;
  c2_symbol *pcVar5;
  c2_symbol *pcVar6;
  
  pcVar5 = g_local_symbol_free;
  pcVar6 = g_temp_symbol_free;
  switch(g_symbol_pool_by_class[kind]) {
  case 0:
    if (g_temp_symbol_free == (c2_symbol *)0x0) {
      if (g_pool_a_symbol_chunk->end <= g_pool_a_symbol_chunk->cursor) {
        g_pool_a_symbol_chunk = symbol_chunk_new();
      }
      pcVar6 = g_pool_a_symbol_chunk->cursor;
      g_pool_a_symbol_chunk->cursor = pcVar6 + 1;
      return pcVar6;
    }
    uVar1 = g_temp_symbol_free->id;
    pcVar5 = g_temp_symbol_free;
    g_temp_symbol_free = (g_temp_symbol_free->u28).free_next;
    for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
      pcVar5->fe = (c2_fe_symbol *)0x0;
      pcVar5 = (c2_symbol *)&pcVar5->cls;
    }
    pcVar6->id = uVar1;
    return pcVar6;
  case 1:
    if (g_local_symbol_free != (c2_symbol *)0x0) {
      uVar1 = g_local_symbol_free->id;
      pcVar6 = g_local_symbol_free;
      g_local_symbol_free = (g_local_symbol_free->u28).free_next;
      for (iVar4 = 0x15; pcVar2 = g_local_symbol_ids, iVar4 != 0; iVar4 = iVar4 + -1) {
        pcVar6->fe = (c2_fe_symbol *)0x0;
        pcVar6 = (c2_symbol *)&pcVar6->cls;
      }
      pcVar5->id = uVar1;
      bitset_set(pcVar2,uVar1);
      return pcVar5;
    }
    if (g_pool_b_symbol_chunk->end <= g_pool_b_symbol_chunk->cursor) {
      g_pool_b_symbol_chunk = symbol_chunk_new();
    }
    pcVar2 = g_local_symbol_ids;
    pcVar6 = g_pool_b_symbol_chunk->cursor;
    g_pool_b_symbol_chunk->cursor = pcVar6 + 1;
    bitset_set(pcVar2,pcVar6->id);
    return pcVar6;
  case 2:
    if (g_pool_c_symbol_chunk->end <= g_pool_c_symbol_chunk->cursor) {
      g_pool_c_symbol_chunk = symbol_chunk_new();
    }
    pcVar2 = g_global_symbol_ids;
    pcVar6 = g_pool_c_symbol_chunk->cursor;
    g_pool_c_symbol_chunk->cursor = pcVar6 + 1;
    bitset_set(pcVar2,pcVar6->id);
    return pcVar6;
  case 3:
    pcVar3 = g_pool_d_symbol_chunk;
    if (g_pool_d_symbol_chunk->end <= g_pool_d_symbol_chunk->cursor) {
      pcVar3 = symbol_chunk_new();
      g_pool_d_symbol_chunk = pcVar3;
    }
    break;
  case 4:
    if ((g_pool_e_symbol_chunk == (c2_symbol_chunk *)0x0) ||
       (pcVar3 = g_pool_e_symbol_chunk, g_pool_e_symbol_chunk->end <= g_pool_e_symbol_chunk->cursor)
       ) {
      g_pool_e_symbol_chunk = symbol_chunk_new();
      pcVar6 = g_pool_e_symbol_chunk->cursor;
      g_pool_e_symbol_chunk->cursor = pcVar6 + 1;
      return pcVar6;
    }
  }
  pcVar6 = pcVar3->cursor;
  pcVar3->cursor = pcVar6 + 1;
  return pcVar6;
}

