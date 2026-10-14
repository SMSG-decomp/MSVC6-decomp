char * __cdecl file_make_canonical_path(char *out,char *file,uint size)

{
  char cVar1;
  bool bVar2;
  uchar *puVar3;
  byte *pbVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  c1_u32 *pcVar8;
  c1_u32 *canonical_dst;
  char *pcVar9;
  bool bVar10;
  char path_copy [260];
  
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
    pcVar9 = pcVar5;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar9 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar9;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar8 = (c1_u32 *)(pcVar9 + -uVar6);
  canonical_dst = (c1_u32 *)path_copy;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *canonical_dst = *pcVar8;
    pcVar8 = pcVar8 + 1;
    canonical_dst = canonical_dst + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)canonical_dst = (char)*pcVar8;
    pcVar8 = (c1_u32 *)((int)pcVar8 + 1);
    canonical_dst = (c1_u32 *)((int)canonical_dst + 1);
  }
  uVar6 = 0xffffffff;
  pcVar5 = path_copy;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if ((2 < ~uVar6 - 1) &&
     (file_name_canonicalize((byte *)path_copy),
     ((byte)_mbctype_exref[(byte)path_copy[0] + 1] & 4) == 0)) {
    bVar2 = false;
    if ((path_copy[0] == '\\') && (path_copy[1] == '\\')) {
      bVar2 = true;
    }
    else if ((0x7f < (byte)path_copy[0]) || (path_copy[1] != ':')) goto LAB_10432a98;
    puVar3 = _mbsstr((uchar *)path_copy,".\\");
    if (puVar3 == (uchar *)0x0) {
      bVar10 = true;
      if (!bVar2) {
        puVar3 = _mbsstr((uchar *)path_copy,":\\");
        bVar10 = puVar3 != (uchar *)0x0;
      }
      if (bVar10) {
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
        pcVar9 = out;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar9 = pcVar9 + 1;
        }
        goto LAB_10432a7d;
      }
    }
  }
LAB_10432a98:
  pcVar5 = _fullpath(out,file,size);
  if (pcVar5 == (char *)0x0) {
    pcVar5 = file_copy_name_canonical('\0',file,out);
    return pcVar5;
  }
LAB_10432a7d:
  pbVar4 = file_name_canonicalize((byte *)out);
  return (char *)pbVar4;
}

