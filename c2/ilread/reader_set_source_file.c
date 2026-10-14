int __fastcall reader_set_source_file(char *name)

{
  char cVar1;
  byte bVar2;
  c2_line_run *pcVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  byte *pbVar9;
  char *pcVar10;
  bool bVar11;
  
  pbVar9 = (byte *)g_reader_source_file;
  pbVar4 = (byte *)name;
  pcVar3 = g_line_run_head;
  if (g_reader_source_file != (char *)0x0) {
    do {
      bVar2 = *pbVar9;
      bVar11 = bVar2 < *pbVar4;
      if (bVar2 != *pbVar4) {
LAB_10797320:
        iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_10797313;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar9[1];
      bVar11 = bVar2 < pbVar4[1];
      if (bVar2 != pbVar4[1]) goto LAB_10797320;
      pbVar9 = pbVar9 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_10797313:
    if (iVar5 == 0) {
      return 0;
    }
  }
  for (; pcVar3 != (c2_line_run *)0x0; pcVar3 = pcVar3->older) {
    pbVar9 = (byte *)pcVar3->file;
    pbVar4 = (byte *)name;
    do {
      bVar2 = *pbVar4;
      bVar11 = bVar2 < *pbVar9;
      if (bVar2 != *pbVar9) {
LAB_10731ced:
        iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_10731cf2;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar11 = bVar2 < pbVar9[1];
      if (bVar2 != pbVar9[1]) goto LAB_10731ced;
      pbVar4 = pbVar4 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_10731cf2:
    if (iVar5 == 0) {
      g_reader_source_file = pcVar3->file;
      return 0;
    }
  }
  uVar6 = 0xffffffff;
  pcVar8 = name;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  g_reader_source_file = arena_alloc(0,~uVar6);
  uVar6 = 0xffffffff;
  do {
    pcVar8 = name;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = name + 1;
    cVar1 = *name;
    name = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar8 = pcVar8 + -uVar6;
  pcVar10 = g_reader_source_file;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  return 0;
}

