c1_pdb_blob_table * __fastcall pdb_blob_stream_init(c1_pdb_blob_table *table)

{
  table->stream = (c1xx_pdb_stream *)0x0;
  table->dirty = '\0';
  table->entries = (c1_pdb_blob_entry *)0x0;
  table->count = 0;
  return table;
}

