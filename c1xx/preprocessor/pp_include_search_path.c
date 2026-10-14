int __cdecl pp_include_search_path(byte *name,byte *dir,char parent_mode,char report,byte *out)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint hash;
  byte *pbVar8;
  bool bVar9;
  int local_204;
  byte local_200 [512];
  
  hash = 0;
  local_204 = -1;
  if (out == (byte *)0x0) {
    out = local_200;
  }
  pbVar7 = out;
  if (parent_mode == '\0') {
    if (dir != (byte *)0x0) {
      pcVar2 = "./";
      pbVar5 = dir;
      do {
        bVar1 = *pbVar5;
        bVar9 = bVar1 < (byte)*pcVar2;
        if (bVar1 != *pcVar2) {
LAB_104333af:
          iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_104333b4;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar9 = bVar1 < (byte)pcVar2[1];
        if (bVar1 != pcVar2[1]) goto LAB_104333af;
        pbVar5 = pbVar5 + 2;
        pcVar2 = pcVar2 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_104333b4:
      if (iVar3 != 0) {
        bVar1 = *dir;
        pbVar5 = dir;
        while ((pbVar8 = dir, bVar1 != 0 && (pbVar7 < out + 0x200))) {
          bVar1 = *pbVar8;
          *pbVar7 = bVar1;
          pbVar6 = pbVar7 + 1;
          hash = (uint)bVar1 + (hash >> 4) + hash * 4;
          pbVar5 = pbVar8;
          if (((byte)_mbctype_exref[bVar1 + 1] & 4) != 0) {
            bVar1 = pbVar8[1];
            pbVar5 = pbVar8 + 1;
            *pbVar6 = bVar1;
            hash = (hash >> 4) + hash * 4 + (uint)bVar1;
            pbVar6 = pbVar7 + 2;
          }
          bVar1 = pbVar5[1];
          dir = pbVar5 + 1;
          pbVar5 = pbVar8;
          pbVar7 = pbVar6;
        }
        pcVar2 = strchr(g_opt_pc,(uint)*pbVar5);
        if (pcVar2 == (char *)0x0) {
          *pbVar7 = 0x5c;
          hash = (hash >> 4) + 0x5c + hash * 4;
          pbVar7 = pbVar7 + 1;
        }
      }
    }
  }
  else {
    pbVar5 = (byte *)0x0;
    pbVar8 = dir;
    if (*dir != 0) {
      do {
        if (((byte)_mbctype_exref[*pbVar8 + 1] & 4) == 0) {
          pcVar2 = strchr(g_opt_pc,(uint)*pbVar8);
          if (pcVar2 != (char *)0x0) {
            pbVar5 = pbVar8;
          }
        }
        else {
          pbVar8 = pbVar8 + 1;
        }
        pbVar6 = pbVar8 + 1;
        pbVar8 = pbVar8 + 1;
      } while (*pbVar6 != 0);
      if (pbVar5 != (byte *)0x0) {
        for (; dir <= pbVar5; dir = dir + 1) {
          bVar1 = *dir;
          *pbVar7 = bVar1;
          hash = (hash >> 4) + hash * 4 + (uint)bVar1;
          pbVar7 = pbVar7 + 1;
        }
      }
    }
  }
  uVar4 = 0xffffffff;
  pbVar5 = name;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 != 0);
  if ((byte *)0x200 < pbVar7 + (~uVar4 - (int)out)) {
    *pbVar7 = 0;
    diag_fatal(0x51,out,0x200);
  }
  bVar1 = *name;
  *pbVar7 = bVar1;
  while (bVar1 != 0) {
    name = name + 1;
    hash = (hash >> 4) + hash * 4 + (uint)*pbVar7;
    bVar1 = *name;
    pbVar7 = pbVar7 + 1;
    *pbVar7 = bVar1;
  }
  if (report == '\0') {
    iVar3 = _access((char *)out,0);
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    local_204 = file_open_or_fatal((char *)out,hash,0,1,1);
    if (local_204 != -1) {
      if (local_204 < 0) {
        return local_204;
      }
      if ((g_pch_directive_mode != 1) && (g_auto_pch_creating == 0)) {
        return local_204;
      }
      pragma_section_attribute((char *)out,local_204);
      return local_204;
    }
  }
  *out = 0;
  return local_204;
}

