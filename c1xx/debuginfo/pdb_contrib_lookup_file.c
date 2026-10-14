byte __thiscall pdb_contrib_lookup_file(c1_pdb_session *session,char *file,int *value)

{
  char cVar1;
  byte bVar2;
  int *local_8;
  c1_u32 local_4;
  
  cVar1 = pdb_open_pch_contrib_stream(session);
  if (cVar1 == '\0') {
    return 0;
  }
  bVar2 = pdb_contrib_find_entry(session->blob_table,file,&local_8,&local_4);
  if (bVar2 == 0) {
    *value = 0;
    return 0;
  }
  *value = *local_8;
  return 1;
}

