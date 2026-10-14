byte __fastcall pdb_stream_table_close(fe_pdb_blob_table *table)

{
  byte bVar1;
  
  bVar1 = pdb_blob_stream_flush(table);
  if (table != (fe_pdb_blob_table *)0x0) {
    pdb_blob_stream_destroy(table);
    __3_YAXPAX_Z(table);
  }
  return bVar1;
}

