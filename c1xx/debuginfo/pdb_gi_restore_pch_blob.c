char __fastcall pdb_gi_restore_pch_blob(void *tracker)

{
  int iVar1;
  
  if (g_pdb_gi_pch_blob != (uint *)0x0) {
    iVar1 = (*g_pdb_gi->mre_compiler->vtbl->restore_state)(g_pdb_gi_pch_blob);
    if (iVar1 == 0) {
      diag_error(0x1d7,g_pdb_file_name);
      return '\0';
    }
  }
  return '\x01';
}

