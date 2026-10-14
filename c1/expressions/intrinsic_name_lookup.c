int __cdecl intrinsic_name_lookup(void *name)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined **ppuVar6;
  bool bVar7;
  
  cVar1 = **(char **)((int)name + 4);
  if ((cVar1 < '{') && ('^' < cVar1)) {
    for (ppuVar6 = &g_intrinsic_names + (&g_intrinsic_first_by_char)[cVar1];
        ppuVar6 != &g_intrinsic_names + (&g_intrinsic_end_by_char)[cVar1]; ppuVar6 = ppuVar6 + 1) {
      pbVar4 = *ppuVar6;
      pbVar5 = (byte *)(*(char **)((int)name + 4) + 1);
      do {
        bVar2 = *pbVar4;
        bVar7 = bVar2 < *pbVar5;
        if (bVar2 != *pbVar5) {
LAB_10622a89:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_10622a8e;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar7 = bVar2 < pbVar5[1];
        if (bVar2 != pbVar5[1]) goto LAB_10622a89;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_10622a8e:
      if (iVar3 == 0) {
        return (int)(ppuVar6 + -0x4195556) >> 2;
      }
    }
  }
  return -1;
}

