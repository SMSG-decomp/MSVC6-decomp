void __thiscall pdb_session_close_gi(c1_pdb_session *session,char commit)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pdb_name;
  char *pdb_name_3;
  char *pdb_name_2;
  char text [260];
  
  if (session->pdb == (c1xx_pdb *)0x0) {
    return;
  }
  if (g_last_in_batch != '\0') {
    iVar3 = (*session->mre_compiler->vtbl->release)();
    session->mre_compiler = (c1_mre_compiler *)0x0;
    if (iVar3 == 0) {
      pdb_name_3 = (*session->pdb->vtbl->query_pdb_name)(session->pdb,text);
      diag_error(0x1d7,pdb_name_3);
    }
    iVar3 = (*session->mre->vtbl->close)(session->mre,(uint)(byte)commit);
    if (iVar3 == 0) {
      pdb_name_2 = (*session->pdb->vtbl->query_pdb_name)(session->pdb,text);
      diag_error(0x1d7,pdb_name_2);
    }
    session->mre = (c1_mre_engine *)0x0;
    if (session->namemap != (c1_pdb_namemap *)0x0) {
      return;
    }
    if (session->tpi != (c1_pdb_tpi *)0x0) {
      return;
    }
    (*session->pdb->vtbl->query_pdb_name)(session->pdb,text);
    bVar1 = 1;
    if (session->blob_table != (c1_pdb_blob_table *)0x0) {
      bVar1 = pdb_stream_table_close(session->blob_table);
      session->blob_table = (c1_pdb_blob_table *)0x0;
      bVar1 = bVar1 & 1;
    }
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0'))
        && (iVar3 = (*session->pdb->vtbl->commit)(), iVar3 == 0)) ||
       (iVar3 = (*session->pdb->vtbl->close)(), iVar3 == 0)) {
      bVar2 = 0;
    }
    else {
      bVar2 = 1;
    }
    session->pdb = (c1xx_pdb *)0x0;
    if ((bVar1 & bVar2) != 0) {
      return;
    }
    pdb_name = text;
    goto LAB_10499ed9;
  }
  if (commit == '\0') {
    return;
  }
  if (session->read_only != '\0') {
    return;
  }
  iVar3 = (*session->mre->vtbl->commit)();
  if (iVar3 != 0) {
    bVar1 = 1;
    if (session->blob_table != (c1_pdb_blob_table *)0x0) {
      bVar1 = pdb_stream_table_close(session->blob_table);
      session->blob_table = (c1_pdb_blob_table *)0x0;
      bVar1 = bVar1 & 1;
    }
    if (((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (session->read_only == '\0')) {
      iVar3 = (*session->pdb->vtbl->commit)();
      bVar2 = 0;
      if (iVar3 != 0) goto LAB_10443d81;
    }
    else {
LAB_10443d81:
      bVar2 = 1;
    }
    if ((bVar1 & bVar2) != 0) {
      return;
    }
  }
  pdb_name = (*session->pdb->vtbl->query_pdb_name)(session->pdb,text);
LAB_10499ed9:
  diag_error(0x1d7,pdb_name);
  return;
}

