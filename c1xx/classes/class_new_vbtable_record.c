c1_vtable_record * __cdecl class_new_vbtable_record(c1_symbol *cls,c1_symbol *vbptr_member)

{
  c1_vtable_record *rec;
  int size;
  c1_vtable_slot local_10;
  
  rec = class_vtable_record_new(1,cls,((cls->detail).cls)->vbptr_offset,vbptr_member);
  class_vbtable_slot_init(&local_10,cls,(c1_symbol *)0x0);
  class_vtable_record_append_slot(rec,&local_10);
  size = type_int_size();
  class_vtable_record_reserve_bytes(rec,size);
  return rec;
}

