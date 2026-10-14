void __cdecl class_inherit_base_tables(c1_symbol *base_entry,c1_symbol *cls)

{
  ushort *puVar1;
  c1_vtable_record *src;
  c1_symbol *base_entry_00;
  c1_vtable_record *rec;
  c1_vbase_record *rec_00;
  short sVar2;
  c1_symbol *pcVar3;
  
  base_entry_00 = base_entry;
  pcVar3 = g_scope_vector->entries[(short)base_entry->key_ref];
  class_merge_base_vbases(((cls->detail).cls)->vbases,((pcVar3->detail).cls)->vbases,cls,base_entry)
  ;
  if ((base_entry->key_ref & 0x10000) == 0) {
    base_entry = (c1_symbol *)0x8;
    do {
      puVar1 = *(ushort **)(&base_entry->kind + (int)(pcVar3->detail).cls);
      for (sVar2 = 0; (puVar1 != (ushort *)0x0 && ((int)sVar2 < (int)(uint)*puVar1));
          sVar2 = sVar2 + 1) {
        src = *(c1_vtable_record **)(*(int *)(puVar1 + 4) + sVar2 * 4);
        rec = class_vtable_record_copy(src,0);
        class_vtable_record_set_path(rec,base_entry_00,src);
        class_vtable_record_rebase(rec,base_entry_00,(int)base_entry_00->type);
        vector_push(*(c1_vector **)(&base_entry->kind + (int)&((cls->detail).cls)->size),rec);
      }
      base_entry = (c1_symbol *)&base_entry->flags4;
    } while ((int)base_entry < 0x10);
    return;
  }
  pcVar3 = cls;
  rec_00 = class_new_vbase_record(base_entry,cls,5);
  class_add_vbase_record(((cls->detail).cls)->vbases,rec_00,pcVar3,base_entry);
  return;
}

