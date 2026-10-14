uint __cdecl pdb_namemap_symbol_name(c1_symbol *sym)

{
  int iVar1;
  
  iVar1 = (*g_pdb_gi->name_map->vtbl->getName)
                    (g_pdb_gi->name_map,(sym->key_ref >> 3) - 0x15,(char **)&sym);
  return -(uint)(iVar1 != 0) & (uint)sym;
}

