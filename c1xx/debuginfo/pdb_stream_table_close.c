byte __fastcall pdb_stream_table_close(void *table)

{
  byte bVar1;
  
  bVar1 = pdb_blob_stream_flush(table);
  if (table != (void *)0x0) {
    pdb_blob_stream_destroy(table);
    __3_YAXPAX_Z(table);
  }
  return bVar1;
}

