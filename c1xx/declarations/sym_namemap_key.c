uint sym_namemap_key(uint name_index)

{
  int iVar1;
  uint uVar2;
  uint name_index_out;
  
  name_index_out = 0;
  iVar1 = (*g_pdb_gi->namemap->vtbl->get_ni)(name_index,&name_index_out);
  if (iVar1 != 0) {
    uVar2 = name_index + 0x15;
    if (g_max_namemap_key <= uVar2) {
      g_max_namemap_key = uVar2;
    }
    if (g_max_namemap_key <= g_next_global_key) {
      return uVar2;
    }
  }
  diag_fatal_simple(0x37);
}

