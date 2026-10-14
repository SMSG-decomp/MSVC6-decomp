byte __thiscall pdb_contrib_find_entry(c1_pdb_blob_table *table,char *file,void **data,c1_u32 *size)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  byte local_104 [260];
  uint *entry_cell;
  
  file_make_canonical_path((char *)local_104,file,0x104);
  entry_cell = (uint *)table->entries;
  do {
    if (entry_cell == (uint *)0x0) {
      *size = 0;
      *data = (void *)0x0;
      return 0;
    }
    pbVar2 = (byte *)entry_cell[1];
    pbVar4 = local_104;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_1049a57d:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_1049a54b;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_1049a57d;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_1049a54b:
    if (iVar3 == 0) {
      *size = entry_cell[2];
      *data = (void *)entry_cell[3];
      return 1;
    }
    entry_cell = (uint *)*entry_cell;
  } while( true );
}

