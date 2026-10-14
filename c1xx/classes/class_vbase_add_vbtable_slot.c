void __cdecl class_vbase_add_vbtable_slot(c1_vbase_record *vbase_rec,c1_symbol *cls)

{
  c1_vtable_record *rec;
  int iVar1;
  c1_vtable_slot local_10;
  
  rec = *((cls->detail).cls)->vbtables->data;
  class_vbtable_slot_init(&local_10,cls,vbase_rec->base);
  class_vtable_record_append_slot(rec,&local_10);
  vbase_rec->vbptr_offset = ((cls->detail).cls)->vbptr_offset;
  iVar1 = type_int_size();
  iVar1 = class_vtable_record_reserve_bytes(rec,iVar1);
  vbase_rec->vbase_index = iVar1;
  vbase_rec->member = rec->vptr_member;
  return;
}

