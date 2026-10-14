c1_vtable_record * __cdecl class_vtable_record_copy_for_vbase(c1_vtable_record *src)

{
  c1_u32 *pcVar1;
  c1_vtable_record *pcVar2;
  c1_vtable_slot *pcVar3;
  int iVar4;
  
  pcVar2 = class_vtable_record_copy(src,0);
  if (pcVar2->kind == 0) {
    pcVar2->kind = 2;
    iVar4 = 0;
    while (iVar4 < pcVar2->nslots) {
      pcVar3 = pcVar2->slots + iVar4;
      iVar4 = iVar4 + 1;
      if (pcVar3 == (c1_vtable_slot *)0x0) {
        return pcVar2;
      }
      pcVar1 = &pcVar3->flags;
      *(byte *)pcVar1 = (byte)*pcVar1 | 1;
    }
  }
  else if (pcVar2->kind == 1) {
    pcVar2->kind = 3;
  }
  return pcVar2;
}

