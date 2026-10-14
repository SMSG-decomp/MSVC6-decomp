char __cdecl class_has_virtual_other_than_dtor(c1_symbol *cls)

{
  c1_vbase_vector *pcVar1;
  c1_vtable_slot *pcVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  c1_vtable_vector *pcVar7;
  
  sVar5 = 0;
  sVar6 = 0;
  pcVar7 = ((cls->detail).cls)->vftables;
  pcVar1 = ((cls->detail).cls)->vbases;
  do {
    while ((pcVar7 == (c1_vtable_vector *)0x0 || ((int)(uint)pcVar7->count <= (int)sVar5))) {
      if ((pcVar1 == (c1_vbase_vector *)0x0) ||
         (iVar3 = (int)sVar6, (int)(uint)pcVar1->count <= iVar3)) {
        return '\0';
      }
      sVar6 = sVar6 + 1;
      sVar5 = 0;
      pcVar7 = pcVar1->data[iVar3]->vftables;
    }
    iVar3 = (int)sVar5;
    sVar5 = sVar5 + 1;
    iVar4 = 0;
    while (iVar4 < pcVar7->data[iVar3]->nslots) {
      pcVar2 = pcVar7->data[iVar3]->slots + iVar4;
      iVar4 = iVar4 + 1;
      if (pcVar2 == (c1_vtable_slot *)0x0) break;
      if ((*(byte *)((int)pcVar2->member + -7) & 0x20) != 0x20) {
        return '\x01';
      }
    }
  } while( true );
}

