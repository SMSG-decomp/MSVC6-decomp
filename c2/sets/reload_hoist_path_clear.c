int __fastcall reload_hoist_path_clear(uint32_t n,c2_block *block,c2_block *stop)

{
  c2_bitset *visited;
  int path_clear;
  
  visited = bitset_new(6);
  path_clear = reload_hoist_path_clear_rec(n,block,stop,visited);
  bitset_free(visited);
  return path_clear;
}

