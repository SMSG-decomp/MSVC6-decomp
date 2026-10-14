void __fastcall pdb_close(c1_pdb_session *session)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *message2;
  char text [260];
  char *message;
  
  if (session->pdb == (c1xx_pdb *)0x0) {
    return;
  }
  if (g_last_in_batch != '\0') {
    iVar3 = (*session->namemap->vtbl->close)();
    if (iVar3 == 0) {
      message2 = (char *)(*session->pdb->vtbl->query_pdb_name)(text);
      diag_error(0x1d7,message2);
    }
    session->namemap = (c1_pdb_namemap *)0x0;
    if (session->mre != (c1_mre_engine *)0x0) {
      return;
    }
    if (session->tpi != (c1_pdb_tpi *)0x0) {
      return;
    }
    (*session->pdb->vtbl->query_pdb_name)(text);
    bVar2 = 1;
    if (session->blob_table != (c1_pdb_blob_table *)0x0) {
      bVar2 = pdb_stream_table_close(session->blob_table);
      session->blob_table = (c1_pdb_blob_table *)0x0;
      bVar2 = bVar2 & 1;
    }
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0'))
        && (iVar3 = (*session->pdb->vtbl->commit)(), iVar3 == 0)) ||
       (iVar3 = (*session->pdb->vtbl->close)(), iVar3 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    session->pdb = (c1xx_pdb *)0x0;
    if ((bVar2 & bVar1) != 0) {
      return;
    }
    message = &stack0xfffffef8;
    goto LAB_10499d97;
  }
  if (session->read_only != '\0') {
    return;
  }
  iVar3 = (*session->namemap->vtbl->commit)();
  if (iVar3 != 0) {
    bVar2 = 1;
    if (session->blob_table != (c1_pdb_blob_table *)0x0) {
      bVar2 = pdb_stream_table_close(session->blob_table);
      session->blob_table = (c1_pdb_blob_table *)0x0;
      bVar2 = bVar2 & 1;
    }
    if (((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0')) {
      iVar3 = (*session->pdb->vtbl->commit)();
      bVar1 = 0;
      if (iVar3 != 0) goto LAB_10443fe0;
    }
    else {
LAB_10443fe0:
      bVar1 = 1;
    }
    if ((bVar2 & bVar1) != 0) {
      return;
    }
  }
  message = (char *)(*session->pdb->vtbl->query_pdb_name)(text);
LAB_10499d97:
  diag_error(0x1d7,message);
  return;
}

