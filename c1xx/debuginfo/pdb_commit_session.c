byte __fastcall pdb_commit_session(c1_pdb_session *session)

{
  char cVar1;
  int iVar2;
  
  if (session->pdb == (c1xx_pdb *)0x0) {
    return 1;
  }
  if (session->read_only == '\0') {
    if (session->namemap != (c1_pdb_namemap *)0x0) {
      iVar2 = (*session->namemap->vtbl->commit)();
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (session->tpi != (c1_pdb_tpi *)0x0) {
      iVar2 = (*session->tpi->vtbl->commit)();
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (session->mre != (c1_mre_engine *)0x0) {
      iVar2 = (*session->mre->vtbl->commit)();
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (session->blob_table != (c1_pdb_blob_table *)0x0) {
      cVar1 = pdb_blob_stream_flush(session->blob_table);
      if (cVar1 == '\0') {
        return 0;
      }
    }
    iVar2 = (*session->pdb->vtbl->commit)();
    return iVar2 != 0;
  }
  return 1;
}

