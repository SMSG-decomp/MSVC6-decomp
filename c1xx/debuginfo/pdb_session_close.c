void __fastcall pdb_session_close(c1_pdb_session *session)

{
  if (session->mre != (c1_mre_engine *)0x0) {
    (*session->mre->vtbl->close)(0);
    session->mre = (c1_mre_engine *)0x0;
  }
  if (session->tpi != (c1_pdb_tpi *)0x0) {
    (*session->tpi->vtbl->close)();
    session->tpi = (c1_pdb_tpi *)0x0;
  }
  if (session->namemap != (c1_pdb_namemap *)0x0) {
    (*session->namemap->vtbl->close)();
    session->namemap = (c1_pdb_namemap *)0x0;
  }
  if (session->pdb != (c1xx_pdb *)0x0) {
    (*session->pdb->vtbl->close)();
    session->pdb = (c1xx_pdb *)0x0;
  }
  return;
}

