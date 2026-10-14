byte __thiscall import_enum_table_find(void *table,wchar_t *name)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  uint *entry_cell;
  
  pbVar2 = wide_to_multibyte_arena(name);
  *(byte **)((int)table + 0x404) = pbVar2;
  uVar3 = 0;
  bVar1 = *pbVar2;
  pbVar6 = pbVar2;
  while (bVar1 != 0) {
    uVar3 = (uVar3 >> 4) + uVar3 * 4 + (uint)bVar1;
    pbVar4 = pbVar6 + 1;
    pbVar6 = pbVar6 + 1;
    bVar1 = *pbVar4;
  }
  *(uint *)((int)table + 0x400) = uVar3 & 0xff;
  entry_cell = *(uint **)((int)table + (uVar3 & 0xff) * 4);
  do {
    if (entry_cell == (uint *)0x0) {
      return 0;
    }
    pbVar6 = (byte *)entry_cell[1];
    pbVar4 = pbVar2;
    do {
      bVar1 = *pbVar4;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_1049fb1d:
        iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_1049fb09;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_1049fb1d;
      pbVar4 = pbVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_1049fb09:
    if (iVar5 == 0) {
      *(uint **)((int)table + 0x408) = entry_cell;
      return 1;
    }
    entry_cell = (uint *)*entry_cell;
  } while( true );
}

