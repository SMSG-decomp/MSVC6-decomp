c2_symbol * __fastcall symbol_by_id(uint32_t id)

{
  return g_symbol_chunk_index[id >> 5]->syms + (id & 0x1f);
}

