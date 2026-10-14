void __thiscall pdb_record_pch_contribution(void *this,char *file,int value)

{
  char cVar1;
  
  cVar1 = pdb_open_pch_contrib_stream(this);
  if (cVar1 != '\0') {
    cVar1 = named_blob_list_store(*(c1_pdb_blob_table **)((int)this + 0x14),file,(c1_u8 *)&value,4);
    if (cVar1 == '\0') {
      diag_fatal_simple(0x3c);
    }
  }
  return;
}

