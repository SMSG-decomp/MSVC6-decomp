char __cdecl class_vbase_find_vbtable_slot(c1_vbase_record *vbase_rec,c1_symbol *cls)

{
  c1_vtable_record *rec;
  int iVar1;
  c1_vtable_slot *slot;
  
  rec = class_first_vbtable_record(cls);
  iVar1 = 0;
  while( true ) {
    if (rec->nslots <= iVar1) {
      return '\0';
    }
    slot = rec->slots + iVar1;
    iVar1 = iVar1 + 1;
    if (slot == (c1_vtable_slot *)0x0) break;
    if ((c1_symbol *)slot->path_offset == vbase_rec->base) {
      iVar1 = class_vtable_vptr_offset(rec);
      vbase_rec->vbptr_offset = iVar1;
      iVar1 = class_vtable_slot_byte_offset(slot,rec);
      vbase_rec->vbase_index = iVar1;
      vbase_rec->member = rec->vptr_member;
      return '\x01';
    }
  }
  return '\0';
}

