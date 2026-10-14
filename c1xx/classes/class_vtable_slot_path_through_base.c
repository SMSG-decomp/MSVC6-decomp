void __cdecl class_vtable_slot_path_through_base(int *path,c1_symbol *base_entry)

{
  if ((base_entry->key_ref & 0x10000) == 0) {
    class_vtable_slot_path_add_offset(path,(int)base_entry->type);
    return;
  }
  class_vtable_slot_path_set_vbase(path,g_scope_vector->entries[(short)base_entry->key_ref]);
  return;
}

