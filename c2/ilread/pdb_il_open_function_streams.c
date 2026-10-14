int pdb_il_open_function_streams(void)

{
  c2_pdb_il_pending *_Memory;
  int iVar1;
  int iVar2;
  
  if (g_pdb_il_module_count == 0) {
    return 1;
  }
  iVar1 = ILStoreOpen(g_pdb,0,&g_pdb_il_store);
  if (iVar1 == 0) {
    fatal_error(300,g_pdb_name);
  }
  g_pdb_il_modules = malloc(g_pdb_il_module_count * 4);
  iVar1 = g_pdb_il_module_count;
  while( true ) {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return 1;
    }
    iVar2 = ILStoreGetILMod(g_pdb_il_store,g_pdb_il_pending_modules->module_name,
                            g_pdb_il_modules + iVar1);
    _Memory = g_pdb_il_pending_modules;
    if (iVar2 == 0) break;
    g_pdb_il_pending_modules = g_pdb_il_pending_modules->next;
    free(_Memory);
  }
  fatal_error(300,g_pdb_name);
}

