char __thiscall
pdb_open_minimal_rebuild_engine(c1_pdb_session *session,c1_pdb_session *types_session)

{
  int iVar1;
  int pdb_word0;
  int pdb_word1;
  c1_pdb_tpi *local_114;
  c1xx_pdb *local_110;
  int open_arg2;
  int open_arg3;
  char error_text [260];
  
  pdb_word0 = (int)session->pdb;
  pdb_word1 = (int)session->namemap;
  local_110 = types_session->pdb;
  local_114 = types_session->tpi;
  open_arg2 = 0;
  open_arg3 = 0;
  iVar1 = MREngine::FOpen((MREngine **)&session->mre,(MreToPdb *)&pdb_word0,1,0);
  if (iVar1 != 0) {
    (*session->mre->vtbl->query_compiler)(&session->mre_compiler,types_session->tpi);
    return '\x01';
  }
  (*session->pdb->vtbl->query_pdb_name)(error_text);
  diag_error(0x1d7,&open_arg3);
  return '\0';
}

