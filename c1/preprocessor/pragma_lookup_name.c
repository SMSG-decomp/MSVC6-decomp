int __cdecl pragma_lookup_name(char *name)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined **ppuVar6;
  bool bVar7;
  
  cVar1 = *name;
  if ('^' < cVar1) {
    for (ppuVar6 = &g_pragma_names + (char)(&g_pragma_name_first_by_char)[cVar1];
        ppuVar6 != &g_pragma_names + (char)(&g_pragma_letter_end)[cVar1]; ppuVar6 = ppuVar6 + 1) {
      pbVar4 = *ppuVar6;
      pbVar5 = (byte *)(name + 1);
      do {
        bVar2 = *pbVar4;
        bVar7 = bVar2 < *pbVar5;
        if (bVar2 != *pbVar5) {
LAB_106116e6:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_106116eb;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar7 = bVar2 < pbVar5[1];
        if (bVar2 != pbVar5[1]) goto LAB_106116e6;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_106116eb:
      if (iVar3 == 0) {
        return g_pragma_codes[(int)(ppuVar6 + -0x4194e96) >> 2];
      }
    }
  }
  return -1;
}

