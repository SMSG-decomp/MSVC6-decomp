void __cdecl class_vbase_record_free_slot_arrays(c1_vbase_record *rec)

{
  c1_vtable_vector *pcVar1;
  int iVar2;
  c1_vtable_vector **ppcVar3;
  int iVar4;
  short sVar5;
  
  ppcVar3 = &rec->vftables;
  iVar4 = 2;
  do {
    pcVar1 = *ppcVar3;
    sVar5 = 0;
    while (pcVar1 != (c1_vtable_vector *)0x0) {
      iVar2 = (int)sVar5;
      if ((int)(uint)pcVar1->count <= iVar2) break;
      sVar5 = sVar5 + 1;
      class_vtable_record_free_slots(pcVar1->data[iVar2]);
    }
    ppcVar3 = ppcVar3 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return;
    }
  } while( true );
}

