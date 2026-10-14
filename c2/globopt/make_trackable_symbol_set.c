c2_bitset * __fastcall make_trackable_symbol_set(int arena)

{
  c2_bitset *dst;
  
  dst = bitset_new(arena);
  bitset_or(dst,g_local_symbol_ids);
  bitset_or(dst,g_global_symbol_ids);
  return dst;
}

