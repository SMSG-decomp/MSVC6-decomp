void __thiscall il_file_open(fe_il_buffer *buf,byte *prefix,char *suffix,char *mode)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  FILE *pFVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uchar *puVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  uchar *puVar13;
  bool bVar14;
  
  pcVar8 = "nul";
  pbVar5 = prefix;
  do {
    bVar2 = *pbVar5;
    bVar14 = bVar2 < (byte)*pcVar8;
    if (bVar2 != *pcVar8) {
LAB_10615378:
      iVar3 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
      goto LAB_1061537d;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar5[1];
    bVar14 = bVar2 < (byte)pcVar8[1];
    if (bVar2 != pcVar8[1]) goto LAB_10615378;
    pbVar5 = pbVar5 + 2;
    pcVar8 = pcVar8 + 2;
  } while (bVar2 != 0);
  iVar3 = 0;
LAB_1061537d:
  if (iVar3 == 0) {
    suffix = (char *)0x0;
  }
  uVar6 = 0xffffffff;
  do {
    pbVar5 = prefix;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pbVar5 = prefix + 1;
    bVar2 = *prefix;
    prefix = pbVar5;
  } while (bVar2 != 0);
  uVar6 = ~uVar6;
  pcVar8 = buf->name;
  pbVar5 = pbVar5 + -uVar6;
  pcVar10 = pcVar8;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pbVar5;
    pbVar5 = pbVar5 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    pcVar10 = pcVar10 + 1;
  }
  if (suffix != (char *)0x0) {
    uVar6 = 0xffffffff;
    do {
      pcVar10 = suffix;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar10 = suffix + 1;
      cVar1 = *suffix;
      suffix = pcVar10;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar3 = -1;
    pcVar11 = pcVar8;
    do {
      pcVar12 = pcVar11;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar12 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar12;
    } while (cVar1 != '\0');
    puVar9 = (uchar *)(pcVar10 + -uVar6);
    puVar13 = (uchar *)(pcVar12 + -1);
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)puVar13 = *(undefined4 *)puVar9;
      puVar9 = puVar9 + 4;
      puVar13 = puVar13 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
  }
  pFVar4 = fopen(pcVar8,mode);
  buf->file = pFVar4;
  if (pFVar4 == (FILE *)0x0) {
    diag_fatal_file_errno(0x53,0x153,pcVar8);
  }
  setvbuf(buf->file,(char *)0x0,0,0x1000);
  return;
}

