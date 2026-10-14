void __cdecl pch_begin_write(void)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  char *pdb_name_2;
  char *pdb_name;
  int iVar4;
  char pdb_name_buf [244];
  uint call_ret_slot;
  
  g_pch_file = (FILE *)fopen(g_pch_file_name,"w+b");
  if (g_pch_file == (FILE *)0x0) {
    diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
  }
  _g_io_result = fseek((FILE *)g_pch_file,0x3f4,1);
  if (_g_io_result != 0) {
    diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
  }
  il_emit_symbol(6,(c1_symbol *)0x0);
  if ((g_opt_Zi == '\0') || (g_pch_debug_in_object == '\0')) goto LAB_1048c8af;
  debug_finish();
  if (g_il_db.bytes.start + g_il_db.bytes.size < g_il_db.bytes.cur + 2) {
    iVar4 = il_buffer_grow(&g_il_db.bytes,2);
    bVar2 = 0;
    if (iVar4 != 0) goto LAB_1048c885;
  }
  else {
LAB_1048c885:
    bVar2 = 1;
  }
  g_il_db.open = g_il_db.open & bVar2;
  if (g_il_db.open != 0) {
    *g_il_db.bytes.cur = '\x0f';
    g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
  }
LAB_1048c8af:
  pch_finish_il();
  g_pch_header.gl_size = il_file_write_buffer(0x104de9e8);
  g_pch_header.in_size = il_file_write_buffer(0x104de788);
  if ((g_opt_Zi != '\0') &&
     ((g_pch_debug_in_object != '\0' ||
      ((g_auto_pch_creating != 0 && (g_debug_types_in_pdb == '\0')))))) {
    g_pch_header.db_size = il_file_write_buffer(0x104dec48);
    il_emit_debug_record_10();
    pch_write_finish();
    return;
  }
  if ((g_browse_file != (char *)0x0) && ((g_pch_directive_mode == 1 || (g_auto_pch_creating != 0))))
  {
    if (g_file_copy_buffer == (void *)0x0) {
      g_file_copy_buffer = mem_xmalloc(0x8000);
    }
    _g_io_result = fflush((FILE *)g_browse_sbr_file);
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
  if (g_pdb.pdb != (c1xx_pdb *)0x0) {
    if (g_auto_pch_creating != 0) {
      uVar3 = ftell((FILE *)g_pch_file);
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
        (iVar4 = (*(g_pdb.pdb)->vtbl->get_raw_bytes)(pch_rle_write_bytes), iVar4 == 0)))) {
      pdb_name_2 = (char *)(*(g_pdb.pdb)->vtbl->query_pdb_name)(pdb_name_buf);
      diag_error(0x1d7,pdb_name_2);
    }
  }
  if (g_pdb_split.pdb != (c1xx_pdb *)0x0) {
    if (g_auto_pch_creating != 0) {
      uVar3 = g_pch_header.pdb_copy_offset;
      if ((g_pdb.pdb == (c1xx_pdb *)0x0) &&
         (_g_io_result = ftell((FILE *)g_pch_file), uVar3 = _g_io_result, _g_io_result == 0xffffffff
         )) {
        uVar3 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.pdb_copy_offset = uVar3;
      pch_rle_begin(&g_pch_header.idb_copy_size);
    }
    iVar4 = (*g_idb->vtbl->idb_commit)(g_idb);
    if (((iVar4 == 0) || (bVar2 = pdb_commit_session(&g_pdb_split), bVar2 == 0)) ||
       ((g_auto_pch_creating != 0 &&
        (iVar4 = (*(g_pdb_split.pdb)->vtbl->get_raw_bytes)(pch_rle_write_bytes), iVar4 == 0)))) {
      pdb_name = (char *)(*(g_pdb_split.pdb)->vtbl->query_pdb_name)(pdb_name_buf);
      diag_error(0x1d7,pdb_name);
    }
  }
  return;
}

