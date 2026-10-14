void __thiscall il_file_open(c1_il_buffer *buf,char *prefix,char *suffix,char *mode)

{
  char *_Filename;
  char cVar1;
  byte bVar2;
  int iVar3;
  FILE *pFVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  c1_u8 *pcVar9;
  char *pcVar10;
  char *pcVar11;
  c1_u8 *pcVar12;
  bool bVar13;
  
  pcVar8 = "nul";
  pbVar5 = (byte *)prefix;
  do {
    bVar2 = *pbVar5;
    bVar13 = bVar2 < (byte)*pcVar8;
    if (bVar2 != *pcVar8) {
LAB_1043f2b0:
      iVar3 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      goto LAB_1043f2b5;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar5[1];
    bVar13 = bVar2 < (byte)pcVar8[1];
    if (bVar2 != pcVar8[1]) goto LAB_1043f2b0;
    pbVar5 = pbVar5 + 2;
    pcVar8 = pcVar8 + 2;
  } while (bVar2 != 0);
  iVar3 = 0;
LAB_1043f2b5:
  if (iVar3 == 0) {
    suffix = (char *)0x0;
  }
  uVar6 = 0xffffffff;
  do {
    pcVar8 = prefix;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = prefix + 1;
    cVar1 = *prefix;
    prefix = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  _Filename = buf->name;
  pcVar8 = pcVar8 + -uVar6;
  pcVar10 = _Filename;
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
  if (suffix != (char *)0x0) {
    uVar6 = 0xffffffff;
    do {
      pcVar8 = suffix;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar8 = suffix + 1;
      cVar1 = *suffix;
      suffix = pcVar8;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar3 = -1;
    pcVar10 = _Filename;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar9 = (c1_u8 *)(pcVar8 + -uVar6);
    pcVar12 = (c1_u8 *)(pcVar11 + -1);
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar12 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  pFVar4 = fopen(_Filename,mode);
  buf->file = (FILE *)pFVar4;
  if (pFVar4 == (FILE *)0x0) {
    diag_fatal_file_errno(0x53,0x153,_Filename);
  }
  setvbuf((FILE *)buf->file,(char *)0x0,0,0x1000);
  return;
}

