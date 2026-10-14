void __fastcall pdb_session_close_types(c1_pdb_state *session)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  char acStack_104 [260];
  
  if (session->pdb == (PDB *)0x0) {
    return;
  }
  if (g_last_in_batch != '\0') {
    iVar3 = (*session->tpi->vtbl->Close)(session->tpi);
    if (iVar3 == 0) {
      pcVar4 = (*session->pdb->vtbl->QueryPDBName)(session->pdb,acStack_104);
      diag_error(0x1d7,pcVar4);
    }
    session->tpi = (TPI *)0x0;
    if (session->name_map != (NameMap *)0x0) {
      return;
    }
    if (session->mre != (MREngine *)0x0) {
      return;
    }
    (*session->pdb->vtbl->QueryPDBName)(session->pdb,acStack_104);
    bVar2 = 1;
    if (session->stream_table != (fe_pdb_blob_table *)0x0) {
      bVar2 = pdb_stream_table_close(session->stream_table);
      session->stream_table = (fe_pdb_blob_table *)0x0;
      bVar2 = bVar2 & 1;
    }
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0'))
        && (iVar3 = (*session->pdb->vtbl->Commit)(session->pdb), iVar3 == 0)) ||
       (iVar3 = (*session->pdb->vtbl->Close)(session->pdb), iVar3 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    session->pdb = (PDB *)0x0;
    if ((bVar2 & bVar1) != 0) {
      return;
    }
    pcVar4 = acStack_104;
    goto LAB_1064ceb9;
  }
  if (session->read_only != '\0') {
    return;
  }
  iVar3 = (*session->tpi->vtbl->Commit)(session->tpi);
  if (iVar3 != 0) {
    bVar2 = 1;
    if (session->stream_table != (fe_pdb_blob_table *)0x0) {
      bVar2 = pdb_stream_table_close(session->stream_table);
      session->stream_table = (fe_pdb_blob_table *)0x0;
      bVar2 = bVar2 & 1;
    }
    if (((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0')) {
      iVar3 = (*session->pdb->vtbl->Commit)(session->pdb);
      bVar1 = 0;
      if (iVar3 != 0) goto LAB_1064ce9f;
    }
    else {
LAB_1064ce9f:
      bVar1 = 1;
    }
    if ((bVar2 & bVar1) != 0) {
      return;
    }
  }
  pcVar4 = (*session->pdb->vtbl->QueryPDBName)(session->pdb,acStack_104);
LAB_1064ceb9:
  diag_error(0x1d7,pcVar4);
  return;
}

