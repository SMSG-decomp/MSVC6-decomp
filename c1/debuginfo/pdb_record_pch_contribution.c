void __thiscall pdb_record_pch_contribution(c1_pdb_state *pdb,char *file,int value)

{
  char cVar1;
  
  cVar1 = pdb_open_pch_contrib_stream(pdb);
  if (cVar1 != '\0') {
    cVar1 = named_blob_list_store(pdb->stream_table,file,&value,4);
    if (cVar1 == '\0') {
      diag_fatal_simple(0x3c);
    }
  }
  return;
}

