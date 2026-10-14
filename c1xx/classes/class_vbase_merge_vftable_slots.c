void __cdecl
class_vbase_merge_vftable_slots(c1_symbol *cls,c1_vbase_record *existing,c1_vbase_record *rec)

{
  c1_vtable_vector *pcVar1;
  c1_vtable_vector *pcVar2;
  c1_vtable_record *pcVar3;
  int iVar4;
  c1_vtable_slot *other;
  c1_vtable_slot *slot;
  int iVar5;
  int iVar6;
  short local_14;
  c1_vtable_record *local_10;
  short local_8;
  
  pcVar1 = existing->vftables;
  pcVar2 = rec->vftables;
  local_14 = 0;
  local_8 = 0;
  do {
    if ((pcVar1 != (c1_vtable_vector *)0x0) &&
       (iVar4 = (int)local_14, iVar4 < (int)(uint)pcVar1->count)) {
      local_14 = local_14 + 1;
      local_10 = pcVar1->data[iVar4];
    }
    if ((pcVar2 == (c1_vtable_vector *)0x0) ||
       (iVar4 = (int)local_8, (int)(uint)pcVar2->count <= iVar4)) {
      if (existing->access < rec->access) {
        existing->access = rec->access;
      }
      return;
    }
    local_8 = local_8 + 1;
    iVar6 = 0;
    iVar5 = 0;
    pcVar3 = pcVar2->data[iVar4];
    while( true ) {
      if (iVar6 < local_10->nslots) {
        slot = local_10->slots + iVar6;
        iVar6 = iVar6 + 1;
      }
      else {
        slot = (c1_vtable_slot *)0x0;
      }
      if (pcVar3->nslots <= iVar5) break;
      other = pcVar3->slots + iVar5;
      iVar5 = iVar5 + 1;
      if (other == (c1_vtable_slot *)0x0) break;
      class_vtable_slot_merge(slot,other);
    }
  } while( true );
}

