char __cdecl class_overrides_vbase_virtual(c1_symbol *cls,c1_symbol *vbase)

{
  c1_vtable_vector *pcVar1;
  c1_vtable_record *pcVar2;
  c1_sym_link *base_fn;
  char cVar3;
  byte bVar4;
  int iVar5;
  c1_vtable_slot *pcVar6;
  c1_sym_link *fn;
  short sVar7;
  c1_symbol *pcVar8;
  int iVar9;
  c1_symbol *pcVar10;
  c1_member_iter local_28;
  c1xx_ovl_set_iter local_10;
  
  class_member_iter_init(&local_28,&cls->name,2);
  ovl_set_iter_init(&local_10,(void *)0x0);
LAB_104ae515:
  do {
    do {
      while (cVar3 = sym_overload_iter_next(&local_10), cVar3 == '\0') {
        cVar3 = class_member_iter_next(&local_28);
        if (cVar3 == '\0') {
          return '\0';
        }
        sym_overload_iter_init(&local_10,local_28.current);
      }
      pcVar8 = (c1_symbol *)&local_10.current[-1].position;
      bVar4 = (byte)local_10.current[-1].position & 0x1f;
      pcVar10 = pcVar8;
      if (bVar4 == 0x1a) {
        pcVar10 = (((local_10.current)->type).alias)->target;
      }
    } while ((pcVar10->flags1 & 0x20) == 0x20);
    if (bVar4 == 0x1a) {
      pcVar8 = (((local_10.current)->type).alias)->target;
    }
  } while ((*(byte *)((int)&pcVar8->tail + 8) & 4) != 0);
  sVar7 = 0;
  pcVar1 = ((vbase->detail).cls)->vftables;
  fn = local_10.current;
  do {
    if ((pcVar1 == (c1_vtable_vector *)0x0) ||
       (iVar5 = (int)sVar7, (int)(uint)pcVar1->count <= iVar5)) goto LAB_104ae515;
    sVar7 = sVar7 + 1;
    iVar9 = 0;
    pcVar2 = pcVar1->data[iVar5];
    while (iVar9 < pcVar2->nslots) {
      pcVar6 = pcVar2->slots + iVar9;
      iVar9 = iVar9 + 1;
      if (pcVar6 == (c1_vtable_slot *)0x0) break;
      base_fn = (c1_sym_link *)pcVar6->member;
      if ((fn->name == base_fn->name) &&
         (cVar3 = class_check_override_return_type(fn,base_fn,cls,'\0'), fn = local_10.current,
         cVar3 != '\0')) {
        return '\x01';
      }
    }
  } while( true );
}

