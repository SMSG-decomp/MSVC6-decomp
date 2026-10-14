void __thiscall pdb_session_close_gi(c1_pdb_state *session,char flag)

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
    iVar3 = (*session->mre_driver->vtbl->FRelease)(session->mre_driver);
    session->mre_driver = (MRECmp *)0x0;
    if (iVar3 == 0) {
      pcVar4 = (*session->pdb->vtbl->QueryPDBName)(session->pdb,acStack_104);
      diag_error(0x1d7,pcVar4);
    }
    iVar3 = (*session->mre->vtbl->FClose)(session->mre,(uint)(byte)flag);
    if (iVar3 == 0) {
      pcVar4 = (*session->pdb->vtbl->QueryPDBName)(session->pdb,acStack_104);
      diag_error(0x1d7,pcVar4);
    }
    session->mre = (MREngine *)0x0;
    if (session->name_map != (NameMap *)0x0) {
      return;
    }
    if (session->tpi != (TPI *)0x0) {
      return;
    }
    (*session->pdb->vtbl->QueryPDBName)(session->pdb,acStack_104);
    bVar1 = 1;
    if (session->stream_table != (fe_pdb_blob_table *)0x0) {
      bVar1 = pdb_stream_table_close(session->stream_table);
      session->stream_table = (fe_pdb_blob_table *)0x0;
      bVar1 = bVar1 & 1;
    }
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0'))
        && (iVar3 = (*session->pdb->vtbl->Commit)(session->pdb), iVar3 == 0)) ||
       (iVar3 = (*session->pdb->vtbl->Close)(session->pdb), iVar3 == 0)) {
      bVar2 = 0;
    }
    else {
      bVar2 = 1;
    }
    session->pdb = (PDB *)0x0;
    if ((bVar1 & bVar2) != 0) {
      return;
    }
    pcVar4 = acStack_104;
    goto LAB_1064cfb9;
  }
  if (flag == '\0') {
    return;
  }
  if (session->read_only != '\0') {
    return;
  }
  iVar3 = (*session->mre->vtbl->commit)(session->mre);
  if (iVar3 != 0) {
    bVar1 = 1;
    if (session->stream_table != (fe_pdb_blob_table *)0x0) {
      bVar1 = pdb_stream_table_close(session->stream_table);
      session->stream_table = (fe_pdb_blob_table *)0x0;
      bVar1 = bVar1 & 1;
    }
    if (((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0')) {
      iVar3 = (*session->pdb->vtbl->Commit)(session->pdb);
      bVar2 = 0;
      if (iVar3 != 0) goto LAB_1064cf9f;
    }
    else {
LAB_1064cf9f:
      bVar2 = 1;
    }
    if ((bVar1 & bVar2) != 0) {
      return;
    }
  }
  pcVar4 = (*session->pdb->vtbl->QueryPDBName)(session->pdb,acStack_104);
LAB_1064cfb9:
  diag_error(0x1d7,pcVar4);
  return;
}

