uint __cdecl pdb_namemap_symbol_name(c1_symbol *sym)

{
  int iVar1;
  
  iVar1 = (*g_pdb_gi->namemap->vtbl->get_name)((sym->key_ref >> 3) - 0x15);
  return -(uint)(iVar1 != 0) & (uint)&sym;
}

