void __cdecl class_vbase_record_rebase(c1_vbase_record *rec,c1_symbol *base_entry,int offset)

{
  ushort uVar1;
  c1_symbol *pcVar2;
  c1_vbase_record *pcVar3;
  c1_u8 cVar4;
  int iVar5;
  short sVar6;
  int local_4;
  
  pcVar3 = rec;
  rec = (c1_vbase_record *)&rec->vftables;
  local_4 = 2;
  do {
    sVar6 = 0;
    pcVar2 = rec->base;
    while (pcVar2 != (c1_symbol *)0x0) {
      iVar5 = (int)sVar6;
      uVar1._0_1_ = pcVar2->kind;
      uVar1._1_1_ = pcVar2->flags1;
      if ((int)(uint)uVar1 <= iVar5) break;
      sVar6 = sVar6 + 1;
      class_vtable_record_rebase
                (*(c1_vtable_record **)(pcVar2->name->pad12 + iVar5 * 4 + -0x12),base_entry,
                 pcVar3->offset);
    }
    rec = (c1_vbase_record *)&rec->offset;
    local_4 = local_4 + -1;
    if (local_4 == 0) {
      cVar4 = access_compose(pcVar3->access,base_entry->flags2 & 3);
      pcVar3->access = cVar4;
      return;
    }
  } while( true );
}

