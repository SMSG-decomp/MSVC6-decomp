char __fastcall pdb_open_pch_contrib_stream(c1_pdb_session *session)

{
  char cVar1;
  char *message;
  char error_text [260];
  
  if (session->blob_table == (c1_pdb_blob_table *)0x0) {
    cVar1 = pdb_blob_stream_open(session->pdb,"/fe/contrib/pch",&session->blob_table);
    if (cVar1 == '\0') {
      message = (char *)(*session->pdb->vtbl->query_pdb_name)(error_text);
      diag_error(0x1d7,message);
      return '\0';
    }
  }
  return '\x01';
}

