byte __thiscall pdb_contrib_find_entry(fe_pdb_blob_table *table,char *file,void **data,uint *size)

{
  byte bVar1;
  fe_pdb_blob_entry *pfVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  byte local_104 [260];
  
  file_make_canonical_path((char *)local_104,file,0x104);
  pfVar2 = table->entries;
  do {
    if (pfVar2 == (fe_pdb_blob_entry *)0x0) {
      *size = 0;
      *data = (void *)0x0;
      return 0;
    }
    pbVar3 = (byte *)pfVar2->name;
    pbVar5 = local_104;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_1064da8c:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_1064da5a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_1064da8c;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_1064da5a:
    if (iVar4 == 0) {
      *size = pfVar2->size;
      *data = pfVar2->data;
      return 1;
    }
    pfVar2 = pfVar2->next;
  } while( true );
}

