byte __cdecl pp_directive_lookup_name(char *name)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  char **ppcVar6;
  bool bVar7;
  
  cVar1 = *name;
  if ('^' < cVar1) {
    for (ppcVar6 = g_directive_names + *(char *)((int)g_op_flags_table + cVar1 + 0x3c1);
        ppcVar6 != g_directive_names + *(char *)((int)g_op_flags_table + cVar1 + 0x3c2);
        ppcVar6 = ppcVar6 + 1) {
      pbVar3 = (byte *)*ppcVar6;
      pbVar5 = (byte *)(name + 1);
      do {
        bVar2 = *pbVar3;
        bVar7 = bVar2 < *pbVar5;
        if (bVar2 != *pbVar5) {
LAB_1040e8bf:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_1040e8a6;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar3[1];
        bVar7 = bVar2 < pbVar5[1];
        if (bVar2 != pbVar5[1]) goto LAB_1040e8bf;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_1040e8a6:
      if (iVar4 == 0) {
        return *(byte *)(g_directive_codes + ((int)(ppcVar6 + -0x412f450) >> 2));
      }
    }
  }
  return 0xb;
}

