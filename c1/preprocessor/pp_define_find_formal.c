int __cdecl pp_define_find_formal(byte *name)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar4 = 1;
  pbVar6 = g_macro_text_buffer;
  if (0 < g_define_formal_count) {
    do {
      pbVar5 = pbVar6 + 1;
      pbVar3 = name;
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_1060ea73:
          iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_1060ea78;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_1060ea73;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_1060ea78:
      if (iVar2 == 0) {
        return iVar4;
      }
      pbVar6 = pbVar6 + *pbVar6;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= g_define_formal_count);
  }
  return -1;
}

