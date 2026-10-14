void __cdecl class_vtable_record_grow_slots(c1_vtable_record *rec,int extra)

{
  c1_vtable_slot *pcVar1;
  int iVar2;
  
  iVar2 = rec->capacity + extra;
  rec->capacity = iVar2;
  if (rec->slots != (c1_vtable_slot *)0x0) {
    pcVar1 = mem_xrealloc(rec->slots,iVar2 * 0x10);
    rec->slots = pcVar1;
    return;
  }
  pcVar1 = mem_xmalloc(iVar2 * 0x10);
  rec->slots = pcVar1;
  return;
}

