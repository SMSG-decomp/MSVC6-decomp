void __cdecl pch_begin_write(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  char *pdb_name;
  char acStack_104 [244];
  void *return_address;
  
  g_pch_file = fopen(g_pch_file_name,"w+b");
  if (g_pch_file == (FILE *)0x0) {
    return_address = (void *)0x10645027;
    diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
  }
  return_address = (void *)0x1064503d;
  _g_io_result = fseek(g_pch_file,0x3ec,1);
  if (_g_io_result != 0) {
    return_address = (void *)0x1064505c;
    diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
  }
  il_emit_symbol(6,(c1_symbol *)0x0);
  if ((g_opt_Zi == '\0') || (g_pch_debug_in_object == '\0')) goto LAB_106450d6;
  debug_finish();
  if (g_il_db.bytes.pbStart + g_il_db.bytes.cbAlloc < g_il_db.bytes.pbEnd + 2) {
    iVar3 = il_buffer_grow(&g_il_db.bytes,2);
    bVar2 = 0;
    if (iVar3 != 0) goto LAB_106450ac;
  }
  else {
LAB_106450ac:
    bVar2 = 1;
  }
  g_il_db.open = g_il_db.open & bVar2;
  if (g_il_db.open != 0) {
    *g_il_db.bytes.pbEnd = '\x0f';
    g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
  }
LAB_106450d6:
  pch_finish_il();
  g_pch_header.gl_size = il_file_write_buffer(0x10669914);
  g_pch_header.in_size = il_file_write_buffer(0x106696b4);
  if ((g_opt_Zi != '\0') &&
     ((g_pch_debug_in_object != '\0' ||
      ((g_auto_pch_creating != 0 && (g_debug_types_in_pdb == '\0')))))) {
    g_pch_header.db_size = il_file_write_buffer(0x10669b74);
    il_emit_debug_record_10();
  }
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
      uVar4 = ftell(g_pch_file);
      _g_io_result = uVar4;
      if (uVar4 == 0xffffffff) {
        uVar4 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.pdb_copy_offset = uVar4;
      pch_rle_begin(&g_pch_header.pdb_copy_size);
    }
    bVar2 = pdb_commit_session(&g_pdb);
    if ((bVar2 == 0) ||
       ((g_auto_pch_creating != 0 &&
        (iVar3 = (*(g_pdb.pdb)->vtbl->GetRawBytes)(g_pdb.pdb,pch_rle_write_bytes), iVar3 == 0)))) {
      pdb_name = (*(g_pdb.pdb)->vtbl->QueryPDBName)(g_pdb.pdb,acStack_104);
      diag_error(0x1d7,pdb_name);
    }
  }
  if (g_pdb_split.pdb != (PDB *)0x0) {
    if (g_auto_pch_creating != 0) {
      uVar4 = g_pch_header.pdb_copy_offset;
      if ((g_pdb.pdb == (PDB *)0x0) &&
         (_g_io_result = ftell(g_pch_file), uVar4 = _g_io_result, _g_io_result == 0xffffffff)) {
        uVar4 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.pdb_copy_offset = uVar4;
      pch_rle_begin(&g_pch_header.idb_copy_size);
    }
    iVar3 = (*g_idb->vtbl->idb_commit)(g_idb);
    if (((iVar3 == 0) || (bVar2 = pdb_commit_session(&g_pdb_split), bVar2 == 0)) ||
       ((g_auto_pch_creating != 0 &&
        (iVar3 = (*(g_pdb_split.pdb)->vtbl->GetRawBytes)(g_pdb_split.pdb,pch_rle_write_bytes),
        iVar3 == 0)))) {
      pdb_name = (*(g_pdb_split.pdb)->vtbl->QueryPDBName)(g_pdb_split.pdb,acStack_104);
      diag_error(0x1d7,pdb_name);
    }
  }
  return;
}

