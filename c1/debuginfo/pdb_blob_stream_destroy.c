void __fastcall pdb_blob_stream_destroy(fe_pdb_blob_table *table)

{
  fe_pdb_blob_entry *pfVar1;
  Stream *this;
  fe_pdb_blob_entry *pfVar2;
  
  pfVar2 = table->entries;
  while (pfVar2 != (fe_pdb_blob_entry *)0x0) {
    pfVar1 = pfVar2->next;
    __3_YAXPAX_Z(pfVar2->name);
    __3_YAXPAX_Z(pfVar2->data);
    __3_YAXPAX_Z(pfVar2);
    pfVar2 = pfVar1;
  }
  this = table->stream;
  table->entries = (fe_pdb_blob_entry *)0x0;
  if (this != (Stream *)0x0) {
    (*this->vtbl->Release)(this);
    table->stream = (Stream *)0x0;
  }
  return;
}

