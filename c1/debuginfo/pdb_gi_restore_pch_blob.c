uint __cdecl pdb_gi_restore_pch_blob(void)

{
  int iVar1;
  uint extraout_EAX;
  
  iVar1 = 0;
  if (g_pdb_gi_pch_blob != (uint *)0x0) {
    iVar1 = (*g_pdb_gi->mre_driver->vtbl->restore_pch_deps)(g_pdb_gi->mre_driver,g_pdb_gi_pch_blob);
    if (iVar1 == 0) {
      diag_error(0x1d7,&g_pdb_file_name);
      return extraout_EAX & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

