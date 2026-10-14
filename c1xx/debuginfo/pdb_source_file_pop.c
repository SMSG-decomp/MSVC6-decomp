char __fastcall pdb_source_file_pop(c1_mre_tracker *tracker)

{
  int iVar1;
  
  if (tracker->current->file != (c1_mre_file *)0x0) {
    iVar1 = (*g_pdb_gi->mre_compiler->vtbl->pop_file)();
    if (iVar1 == 0) {
      diag_error(0x1d7,g_pdb_file_name);
      return '\0';
    }
  }
  tracker->current = tracker->current->prev;
  return '\x01';
}

