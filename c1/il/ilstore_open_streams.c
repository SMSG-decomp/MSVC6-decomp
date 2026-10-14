void __cdecl ilstore_open_streams(void *pdb)

{
  int iVar1;
  
  iVar1 = (*g_pdb_gi->name_map->vtbl->getNi)(g_pdb_gi->name_map,pdb,&g_ilstore_module_ni);
  if ((iVar1 != 0) && (iVar1 = (*g_ilstore->vtbl->GetILMod)(g_ilstore,pdb,&g_ilmod), iVar1 != 0)) {
    return;
  }
  ilstore_report_error();
  return;
}

