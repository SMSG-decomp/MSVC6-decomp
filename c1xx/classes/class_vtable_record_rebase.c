void __cdecl class_vtable_record_rebase(c1_vtable_record *rec,c1_symbol *base_entry,int offset)

{
  c1_vtable_slot *pcVar1;
  int iVar2;
  
  switch(rec->kind) {
  case 0:
  case 2:
    iVar2 = 0;
    break;
  case 1:
    iVar2 = 0;
    rec->off20 = rec->off20 + offset;
    while( true ) {
      if (rec->nslots <= iVar2) {
        return;
      }
      pcVar1 = rec->slots + iVar2;
      iVar2 = iVar2 + 1;
      if (pcVar1 == (c1_vtable_slot *)0x0) break;
      if (pcVar1->path_offset != 0) {
        pcVar1->member = (int *)((int)pcVar1->member + offset);
      }
    }
    return;
  case 3:
    rec->off24 = offset;
    class_vtable_record_rebase_return();
    return;
  default:
    return;
  }
  while (iVar2 < rec->nslots) {
    pcVar1 = rec->slots + iVar2;
    iVar2 = iVar2 + 1;
    if (pcVar1 == (c1_vtable_slot *)0x0) break;
    class_vtable_slot_path_through_base(&pcVar1->path_offset,base_entry);
  }
  if (rec->kind == 0) {
    rec->off20 = rec->off20 + offset;
    return;
  }
  rec->off24 = offset;
  return;
}

