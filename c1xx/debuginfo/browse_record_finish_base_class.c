void __cdecl browse_record_finish_base_class(c1xx_browse_record *rec,c1_symbol *entry)

{
  byte bVar1;
  
  browse_record_fill_member_reference(&rec->kind,g_scope_vector->entries[(short)entry->key_ref]);
  bVar1 = g_browse_base_access_bits[entry->flags2 & 3];
  rec->type = bVar1;
  if ((entry->key_ref & 0x10000) != 0) {
    rec->type = bVar1 | 1;
  }
  return;
}

