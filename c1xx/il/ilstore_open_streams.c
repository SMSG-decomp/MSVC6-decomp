void __cdecl ilstore_open_streams(char *module_name)

{
  int iVar1;
  
  iVar1 = (*g_pdb_gi->namemap->vtbl->get_ni)(module_name,&g_ilstore_module_ni);
  if ((iVar1 != 0) && (iVar1 = (*g_ilstore->vtbl->get_module)(module_name,&g_ilmod), iVar1 != 0)) {
    return;
  }
  ilstore_report_error();
  return;
}

