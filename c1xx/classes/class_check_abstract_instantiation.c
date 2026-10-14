void __cdecl class_check_abstract_instantiation(c1_symbol *cls)

{
  c1_vbase_vector *pcVar1;
  c1_vtable_record *pcVar2;
  int *piVar3;
  int iVar4;
  c1_vtable_slot *pcVar5;
  short sVar6;
  int iVar7;
  c1_vtable_vector *pcVar8;
  short local_10;
  
  diag_error(0x103,cls);
  sVar6 = 0;
  pcVar1 = ((cls->detail).cls)->vbases;
  pcVar8 = ((cls->detail).cls)->vftables;
  local_10 = 0;
  do {
    while ((pcVar8 == (c1_vtable_vector *)0x0 || ((int)(uint)pcVar8->count <= (int)sVar6))) {
      if ((pcVar1 == (c1_vbase_vector *)0x0) ||
         (iVar4 = (int)local_10, (int)(uint)pcVar1->count <= iVar4)) {
        return;
      }
      local_10 = local_10 + 1;
      sVar6 = 0;
      pcVar8 = pcVar1->data[iVar4]->vftables;
    }
    iVar4 = (int)sVar6;
    sVar6 = sVar6 + 1;
    iVar7 = 0;
    pcVar2 = pcVar8->data[iVar4];
    while (iVar7 < pcVar2->nslots) {
      pcVar5 = pcVar2->slots + iVar7;
      iVar7 = iVar7 + 1;
      if (pcVar5 == (c1_vtable_slot *)0x0) break;
      piVar3 = pcVar5->member;
      if ((*(byte *)(piVar3 + 0xb) & 4) != 0) {
        diag_warning(1,0x103,piVar3 + -2,cls);
      }
    }
  } while( true );
}

