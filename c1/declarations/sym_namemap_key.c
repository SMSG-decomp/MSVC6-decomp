uint sym_namemap_key(uint name_index)

{
  int iVar1;
  NI local_4;
  
  local_4 = 0;
  iVar1 = (*g_pdb_gi->name_map->vtbl->getNi)(g_pdb_gi->name_map,(char *)name_index,&local_4);
  if (iVar1 != 0) {
    local_4 = local_4 + 0x15;
    if (g_max_namemap_key <= local_4) {
      g_max_namemap_key = local_4;
    }
    if (g_max_namemap_key <= g_next_global_key) {
      return local_4;
    }
  }
  diag_fatal_simple(0x37);
}

