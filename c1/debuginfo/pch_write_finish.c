void __cdecl pch_write_finish(void)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  char *pdb_name;
  char local_104 [260];
  
  if ((g_browse_file != (char *)0x0) && ((g_pch_directive_mode == 1 || (g_auto_pch_creating != 0))))
  {
    if (g_file_copy_buffer == (void *)0x0) {
      g_file_copy_buffer = mem_xmalloc(0x8000);
    }
    _g_io_result = fflush(g_browse_sbr_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x58,0x153,(char *)0x0);
    }
    bVar1 = browse_seek_to_saved_offset();
    _g_io_result = (uint)bVar1;
    if (_g_io_result != 1) {
      diag_fatal_file_errno(0x58,0x153,(char *)0x0);
    }
    g_pch_header.browse_size = file_copy_contents(g_browse_sbr_file,g_pch_file,0x7fffffff);
  }
  if (g_file_copy_buffer != (void *)0x0) {
    mem_free(g_file_copy_buffer);
  }
  if (g_pdb.pdb != (PDB *)0x0) {
    if (g_auto_pch_creating != 0) {
      uVar3 = ftell(g_pch_file);
      _g_io_result = uVar3;
      if (uVar3 == 0xffffffff) {
        uVar3 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.pdb_copy_offset = uVar3;
      pch_rle_begin(&g_pch_header.pdb_copy_size);
    }
    bVar2 = pdb_commit_session(&g_pdb);
    if ((bVar2 == 0) ||
       ((g_auto_pch_creating != 0 &&
        (iVar4 = (*(g_pdb.pdb)->vtbl->GetRawBytes)(g_pdb.pdb,pch_rle_write_bytes), iVar4 == 0)))) {
      pdb_name = (*(g_pdb.pdb)->vtbl->QueryPDBName)(g_pdb.pdb,local_104);
      diag_error(0x1d7,pdb_name);
    }
  }
  if (g_pdb_split.pdb != (PDB *)0x0) {
    if (g_auto_pch_creating != 0) {
      uVar3 = g_pch_header.pdb_copy_offset;
      if ((g_pdb.pdb == (PDB *)0x0) &&
         (_g_io_result = ftell(g_pch_file), uVar3 = _g_io_result, _g_io_result == 0xffffffff)) {
        uVar3 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.pdb_copy_offset = uVar3;
      pch_rle_begin(&g_pch_header.idb_copy_size);
    }
    iVar4 = (*g_idb->vtbl->idb_commit)(g_idb);
    if (((iVar4 == 0) || (bVar2 = pdb_commit_session(&g_pdb_split), bVar2 == 0)) ||
       ((g_auto_pch_creating != 0 &&
        (iVar4 = (*(g_pdb_split.pdb)->vtbl->GetRawBytes)(g_pdb_split.pdb,pch_rle_write_bytes),
        iVar4 == 0)))) {
      pdb_name = (*(g_pdb_split.pdb)->vtbl->QueryPDBName)(g_pdb_split.pdb,local_104);
      diag_error(0x1d7,pdb_name);
    }
  }
  return;
}

