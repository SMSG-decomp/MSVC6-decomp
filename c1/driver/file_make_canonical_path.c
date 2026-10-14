int __cdecl file_make_canonical_path(char *out,char *file,uint size)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  uchar *puVar4;
  int extraout_EAX;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *pcVar10;
  bool bVar11;
  byte local_104 [260];
  
  uVar6 = 0xffffffff;
  pcVar5 = file;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (size <= ~uVar6 - 1) {
    diag_fatal(0x51,file,size);
  }
  uVar6 = 0xffffffff;
  pcVar5 = file;
  do {
    pcVar10 = pcVar5;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pbVar8 = (byte *)(pcVar10 + -uVar6);
  pbVar9 = local_104;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
    pbVar8 = pbVar8 + 4;
    pbVar9 = pbVar9 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pbVar9 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar9 = pbVar9 + 1;
  }
  uVar6 = 0xffffffff;
  pbVar8 = local_104;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    bVar2 = *pbVar8;
    pbVar8 = pbVar8 + 1;
  } while (bVar2 != 0);
  if ((2 < ~uVar6 - 1) &&
     (file_name_canonicalize(local_104), ((byte)_mbctype_exref[local_104[0] + 1] & 4) == 0)) {
    bVar3 = false;
    if ((local_104[0] == 0x5c) && (local_104[1] == '\\')) {
      bVar3 = true;
    }
    else if ((0x7f < local_104[0]) || (local_104[1] != ':')) goto LAB_10610584;
    puVar4 = _mbsstr(local_104,".\\");
    if (puVar4 == (uchar *)0x0) {
      bVar11 = true;
      if (!bVar3) {
        puVar4 = _mbsstr(local_104,":\\");
        bVar11 = puVar4 != (uchar *)0x0;
      }
      if (bVar11) {
        uVar6 = 0xffffffff;
        do {
          pcVar5 = file;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar5 = file + 1;
          cVar1 = *file;
          file = pcVar5;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar5 = pcVar5 + -uVar6;
        pcVar10 = out;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar10 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar10 = pcVar10 + 1;
        }
        goto LAB_10610569;
      }
    }
  }
LAB_10610584:
  pcVar5 = _fullpath(out,file,size);
  if (pcVar5 == (char *)0x0) {
    pcVar5 = file_copy_name_canonical('\0',file,out);
    return (int)pcVar5;
  }
LAB_10610569:
  file_name_canonicalize((byte *)out);
  return extraout_EAX;
}

