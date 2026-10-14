fe_pdb_blob_table * __fastcall pdb_blob_stream_init(fe_pdb_blob_table *table)

{
  table->stream = (Stream *)0x0;
  table->dirty = '\0';
  table->entries = (fe_pdb_blob_entry *)0x0;
  table->count = 0;
  return table;
}

