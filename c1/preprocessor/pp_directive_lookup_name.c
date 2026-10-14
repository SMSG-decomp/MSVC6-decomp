byte __cdecl pp_directive_lookup_name(char *name)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  undefined **ppuVar6;
  bool bVar7;
  
  cVar1 = *name;
  if ('^' < cVar1) {
    for (ppuVar6 = &g_directive_names + (char)(&g_directive_letter_index_base)[cVar1];
        ppuVar6 != &g_directive_names + (char)(&g_directive_letter_end)[cVar1];
        ppuVar6 = ppuVar6 + 1) {
      pbVar3 = *ppuVar6;
      pbVar5 = (byte *)(name + 1);
      do {
        bVar2 = *pbVar3;
        bVar7 = bVar2 < *pbVar5;
        if (bVar2 != *pbVar5) {
LAB_10609187:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_1060916e;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar3[1];
        bVar7 = bVar2 < pbVar5[1];
        if (bVar2 != pbVar5[1]) goto LAB_10609187;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_1060916e:
      if (iVar4 == 0) {
        return (byte)g_directive_codes[(int)(ppuVar6 + -0x4194976) >> 2];
      }
    }
  }
  return 0xb;
}

