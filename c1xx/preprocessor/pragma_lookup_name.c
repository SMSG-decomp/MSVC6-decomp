int __cdecl pragma_lookup_name(char *name)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte **entry;
  bool bVar6;
  
  cVar1 = *name;
  if ('^' < cVar1) {
    entry = (byte **)(&g_pragma_names + (char)(&g_pragma_name_first_by_char)[cVar1] * 4);
    if (entry == (byte **)(&g_pragma_names + (char)(&g_pragma_name_end_by_char)[cVar1] * 4)) {
      iVar3 = pragma_lookup_unknown();
      return iVar3;
    }
    do {
      pbVar4 = *entry;
      pbVar5 = (byte *)(name + 1);
      do {
        bVar2 = *pbVar4;
        bVar6 = bVar2 < *pbVar5;
        if (bVar2 != *pbVar5) {
LAB_10431aed:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_10431af2;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar6 = bVar2 < pbVar5[1];
        if (bVar2 != pbVar5[1]) goto LAB_10431aed;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_10431af2:
      if (iVar3 == 0) {
        return g_pragma_codes[(int)(entry + -0x412f8d2) >> 2];
      }
      entry = entry + 1;
    } while (entry != (byte **)(&g_pragma_names + (char)(&g_pragma_name_end_by_char)[cVar1] * 4));
  }
  return -1;
}

