void __cdecl
class_note_base_table_pointers(c1_symbol *cls,c1_symbol *base_entry,char *has_virtual_base)

{
  if ((base_entry->key_ref & 0x10000) == 0) {
    if ((base_entry->key_ref & 0x20000) == 0) {
      class_share_base_table_pointers
                (cls,g_scope_vector->entries[(short)base_entry->key_ref],(int)base_entry->type,0);
    }
    return;
  }
  *has_virtual_base = '\x01';
  return;
}

