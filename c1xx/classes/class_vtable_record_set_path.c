void __cdecl
class_vtable_record_set_path(c1_vtable_record *rec,c1_symbol *base_entry,c1_vtable_record *outer)

{
  c1_symbol *pcVar1;
  
  pcVar1 = g_scope_vector->entries[(short)base_entry->key_ref];
  rec->via_base = base_entry;
  rec->subobject_class = pcVar1;
  rec->outer = outer;
  return;
}

