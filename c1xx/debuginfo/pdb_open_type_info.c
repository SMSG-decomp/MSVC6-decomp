char __fastcall pdb_open_type_info(c1_pdb_session *session)

{
  char *suffix;
  int iVar1;
  c1_pdb_tpi **ppcStack_110;
  
  if ((session->pdb == (c1xx_pdb *)0x0) || (session->tpi == (c1_pdb_tpi *)0x0)) {
    if (session->read_only == '\0') {
      suffix = "w";
      if (g_minimal_rebuild == '\0') {
        suffix = "wi";
      }
    }
    else if (g_minimal_rebuild == '\0') {
      suffix = "ri";
    }
    else {
      suffix = "r";
    }
    ppcStack_110 = &session->tpi;
    iVar1 = (*session->pdb->vtbl->open_tpi)(suffix);
    if (iVar1 == 0) {
      (*session->pdb->vtbl->query_pdb_name)(&stack0xfffffef4);
      diag_error(0x1d7,&ppcStack_110);
      return '\0';
    }
  }
  return '\x01';
}

