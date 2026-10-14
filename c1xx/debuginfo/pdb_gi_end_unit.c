char __thiscall pdb_gi_end_unit(c1_mre_tracker *tracker,char commit)

{
  int iVar1;
  
  if (g_mre_engine != (int *)0x0) {
    (**(code **)(*g_mre_engine + 4))();
  }
  iVar1 = (*g_pdb_gi->mre_compiler->vtbl->close_compiland)(tracker->current->file,commit);
  if (iVar1 != 0) {
    pdb_session_close_gi(g_pdb_gi,commit);
    return '\x01';
  }
  diag_error(0x1d7,g_pdb_file_name);
  return '\0';
}

