void __cdecl vtable_record_make_slot_thunks(c1_vtable_record *rec,c1_symbol *cls)

{
  c1_vtable_slot *slot;
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (rec->nslots <= iVar1) {
      return;
    }
    slot = rec->slots + iVar1;
    iVar1 = iVar1 + 1;
    if (slot == (c1_vtable_slot *)0x0) break;
    vtable_slot_target(slot,cls,rec);
  }
  return;
}

