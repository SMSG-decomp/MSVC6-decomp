void __cdecl class_vtable_record_append_slot(c1_vtable_record *rec,c1_vtable_slot *slot)

{
  short sVar1;
  c1_vtable_slot *pcVar2;
  
  if (rec->nslots == rec->capacity) {
    class_vtable_record_grow_slots(rec,rec->capacity + 10);
  }
  pcVar2 = rec->slots + rec->nslots;
  pcVar2->member = slot->member;
  pcVar2->path_offset = slot->path_offset;
  sVar1 = slot->pad0a;
  pcVar2->vbase_index = slot->vbase_index;
  pcVar2->pad0a = sVar1;
  pcVar2->flags = slot->flags;
  rec->nslots = rec->nslots + 1;
  return;
}

