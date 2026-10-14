char __fastcall pdb_source_file_pop(c1_pdb_source_file **stack)

{
  MREFile *pMVar1;
  
  if ((*stack)->object != (MREFile *)0x0) {
    pMVar1 = (*g_pdb_gi->mre_driver->vtbl->PmrefilePopFile)(g_pdb_gi->mre_driver);
    if (pMVar1 == (MREFile *)0x0) {
      diag_error(0x1d7,&g_pdb_file_name);
      return '\0';
    }
  }
  *stack = (*stack)->next;
  return '\x01';
}

