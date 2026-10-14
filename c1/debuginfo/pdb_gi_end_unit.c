char __thiscall pdb_gi_end_unit(c1_pdb_source_file **stack,uint flag)

{
  int iVar1;
  
  if (g_mre_engine != (int *)0x0) {
    (**(code **)(*g_mre_engine + 4))();
  }
  iVar1 = (*g_pdb_gi->mre_driver->vtbl->FCloseCompiland)
                    (g_pdb_gi->mre_driver,(*stack)->object,flag & 0xff);
  if (iVar1 != 0) {
    pdb_session_close_gi(g_pdb_gi,(char)flag);
    return '\x01';
  }
  diag_error(0x1d7,&g_pdb_file_name);
  return '\0';
}

