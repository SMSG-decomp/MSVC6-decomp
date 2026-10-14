char __fastcall pdb_open_pch_contrib_stream(c1_pdb_state *session)

{
  char cVar1;
  char *pcVar2;
  char local_104 [260];
  
  if (session->stream_table == (fe_pdb_blob_table *)0x0) {
    cVar1 = pdb_blob_stream_open(session->pdb,"/fe/contrib/pch",&session->stream_table);
    if (cVar1 == '\0') {
      pcVar2 = (*session->pdb->vtbl->QueryPDBName)(session->pdb,local_104);
      diag_error(0x1d7,pcVar2);
      return '\0';
    }
  }
  return '\x01';
}

