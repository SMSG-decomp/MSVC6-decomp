char __thiscall named_blob_list_store(fe_pdb_blob_table *table,char *name,void *data,uint size)

{
  byte bVar1;
  fe_pdb_blob_entry *pfVar2;
  fe_pdb_blob_entry *pfVar3;
  byte *pbVar4;
  int iVar5;
  fe_pdb_blob_entry *pfVar6;
  char *pcVar7;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  uint *dst_2;
  uint *dst;
  bool bVar12;
  byte local_104 [260];
  
  table->dirty = '\x01';
  file_make_canonical_path((char *)local_104,name,0x104);
  pfVar6 = table->entries;
  pfVar3 = (fe_pdb_blob_entry *)0x0;
  while (pfVar2 = pfVar6, pfVar2 != (fe_pdb_blob_entry *)0x0) {
    pbVar4 = (byte *)pfVar2->name;
    pbVar11 = local_104;
    do {
      bVar1 = *pbVar4;
      bVar12 = bVar1 < *pbVar11;
      if (bVar1 != *pbVar11) {
LAB_1064d8b5:
        iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_1064d88a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar12 = bVar1 < pbVar11[1];
      if (bVar1 != pbVar11[1]) goto LAB_1064d8b5;
      pbVar4 = pbVar4 + 2;
      pbVar11 = pbVar11 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_1064d88a:
    if (iVar5 == 0) {
      if (pfVar2->size != size) {
        pvVar8 = __2_YAPAXI_Z(size);
        if (pvVar8 == (void *)0x0) {
          return '\0';
        }
        __3_YAXPAX_Z(pfVar2->data);
        pfVar2->data = pvVar8;
        pfVar2->size = size;
      }
      dst_2 = pfVar2->data;
      for (uVar9 = size >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *dst_2 = *(uint *)data;
        data = (uint *)((int)data + 4);
        dst_2 = dst_2 + 1;
      }
      for (uVar9 = size & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(char *)dst_2 = (char)*(uint *)data;
        data = (uint *)((int)data + 1);
        dst_2 = (uint *)((int)dst_2 + 1);
      }
      return '\x01';
    }
    pfVar3 = pfVar2;
    pfVar6 = pfVar2->next;
  }
  pfVar6 = __2_YAPAXI_Z(0x10);
  if (pfVar6 == (fe_pdb_blob_entry *)0x0) {
    return '\0';
  }
  uVar9 = 0xffffffff;
  pbVar11 = local_104;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    bVar1 = *pbVar11;
    pbVar11 = pbVar11 + 1;
  } while (bVar1 != 0);
  pcVar7 = __2_YAPAXI_Z(~uVar9);
  pfVar6->name = pcVar7;
  if (pcVar7 == (char *)0x0) {
    __3_YAXPAX_Z(pfVar6);
    return '\0';
  }
  pfVar6->size = size;
  pvVar8 = __2_YAPAXI_Z(size);
  pfVar6->data = pvVar8;
  if (pvVar8 == (void *)0x0) {
    __3_YAXPAX_Z(pfVar6->name);
    __3_YAXPAX_Z(pfVar6);
    return '\0';
  }
  uVar9 = 0xffffffff;
  pbVar11 = local_104;
  do {
    pbVar4 = pbVar11;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pbVar4 = pbVar11 + 1;
    bVar1 = *pbVar11;
    pbVar11 = pbVar4;
  } while (bVar1 != 0);
  uVar9 = ~uVar9;
  pbVar11 = pbVar4 + -uVar9;
  pbVar4 = (byte *)pfVar6->name;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pbVar4 = *(undefined4 *)pbVar11;
    pbVar11 = pbVar11 + 4;
    pbVar4 = pbVar4 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pbVar4 = *pbVar11;
    pbVar11 = pbVar11 + 1;
    pbVar4 = pbVar4 + 1;
  }
  dst = pfVar6->data;
  for (uVar9 = size >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *dst = *(uint *)data;
    data = (uint *)((int)data + 4);
    dst = dst + 1;
  }
  for (uVar9 = size & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(char *)dst = (char)*(uint *)data;
    data = (uint *)((int)data + 1);
    dst = (uint *)((int)dst + 1);
  }
  pfVar6->next = (fe_pdb_blob_entry *)0x0;
  if (pfVar3 == (fe_pdb_blob_entry *)0x0) {
    table->entries = pfVar6;
  }
  else {
    pfVar3->next = pfVar6;
  }
  table->count = table->count + 1;
  return '\x01';
}

