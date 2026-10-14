char __thiscall named_blob_list_store(c1_pdb_blob_table *table,char *name,c1_u8 *data,uint size)

{
  byte bVar1;
  c1_pdb_blob_entry *pcVar2;
  c1_pdb_blob_entry *pcVar3;
  c1_pdb_blob_entry *pcVar4;
  c1_pdb_blob_entry *node;
  char *pcVar5;
  void *pvVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  c1_u32 *data_dst;
  c1_u32 *data_dst_2;
  bool bVar12;
  byte local_104 [260];
  
  table->dirty = '\x01';
  file_make_canonical_path((char *)local_104,name,0x104);
  pcVar4 = table->entries;
  pcVar3 = (c1_pdb_blob_entry *)0x0;
  while (pcVar2 = pcVar4, pcVar2 != (c1_pdb_blob_entry *)0x0) {
    pbVar7 = (byte *)pcVar2->name;
    pbVar11 = local_104;
    do {
      bVar1 = *pbVar7;
      bVar12 = bVar1 < *pbVar11;
      if (bVar1 != *pbVar11) {
LAB_1049a433:
        iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_1049a421;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar7[1];
      bVar12 = bVar1 < pbVar11[1];
      if (bVar1 != pbVar11[1]) goto LAB_1049a433;
      pbVar7 = pbVar7 + 2;
      pbVar11 = pbVar11 + 2;
    } while (bVar1 != 0);
    iVar8 = 0;
LAB_1049a421:
    if (iVar8 == 0) {
      if (pcVar2->size != size) {
        pvVar6 = __2_YAPAXI_Z(size);
        if (pvVar6 == (void *)0x0) {
          return '\0';
        }
        __3_YAXPAX_Z(pcVar2->data);
        pcVar2->data = pvVar6;
        pcVar2->size = size;
      }
      data_dst_2 = pcVar2->data;
      for (uVar9 = size >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *data_dst_2 = *(c1_u32 *)data;
        data = (c1_u8 *)((int)data + 4);
        data_dst_2 = data_dst_2 + 1;
      }
      for (uVar9 = size & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(char *)data_dst_2 = (char)*(c1_u32 *)data;
        data = (c1_u8 *)((int)data + 1);
        data_dst_2 = (c1_u32 *)((int)data_dst_2 + 1);
      }
      return '\x01';
    }
    pcVar3 = pcVar2;
    pcVar4 = pcVar2->next;
  }
  node = __2_YAPAXI_Z(0x10);
  if (node == (c1_pdb_blob_entry *)0x0) {
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
  pcVar5 = __2_YAPAXI_Z(~uVar9);
  node->name = pcVar5;
  if (pcVar5 == (char *)0x0) {
    __3_YAXPAX_Z(node);
    return '\0';
  }
  node->size = size;
  pvVar6 = __2_YAPAXI_Z(size);
  node->data = pvVar6;
  if (pvVar6 == (void *)0x0) {
    __3_YAXPAX_Z(node->name);
    __3_YAXPAX_Z(node);
    return '\0';
  }
  uVar9 = 0xffffffff;
  pbVar11 = local_104;
  do {
    pbVar7 = pbVar11;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pbVar7 = pbVar11 + 1;
    bVar1 = *pbVar11;
    pbVar11 = pbVar7;
  } while (bVar1 != 0);
  uVar9 = ~uVar9;
  pbVar11 = pbVar7 + -uVar9;
  pbVar7 = (byte *)node->name;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pbVar7 = *(undefined4 *)pbVar11;
    pbVar11 = pbVar11 + 4;
    pbVar7 = pbVar7 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pbVar7 = *pbVar11;
    pbVar11 = pbVar11 + 1;
    pbVar7 = pbVar7 + 1;
  }
  data_dst = node->data;
  for (uVar9 = size >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *data_dst = *(c1_u32 *)data;
    data = (c1_u8 *)((int)data + 4);
    data_dst = data_dst + 1;
  }
  for (uVar9 = size & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(char *)data_dst = (char)*(c1_u32 *)data;
    data = (c1_u8 *)((int)data + 1);
    data_dst = (c1_u32 *)((int)data_dst + 1);
  }
  node->next = (c1_pdb_blob_entry *)0x0;
  if (pcVar3 == (c1_pdb_blob_entry *)0x0) {
    table->entries = node;
  }
  else {
    pcVar3->next = node;
  }
  table->count = table->count + 1;
  return '\x01';
}

