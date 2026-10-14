int __cdecl intrinsic_lookup_by_name(fe_name *name)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  char **intrinsic_name;
  bool bVar6;
  
  cVar1 = *name->text;
  if ((cVar1 < '{') && ('^' < cVar1)) {
    for (intrinsic_name = g_intrinsic_names + *(char *)((int)g_intrinsic_names + cVar1 + 0xa1);
        intrinsic_name != g_intrinsic_names + *(char *)((int)g_intrinsic_names + cVar1 + 0xa2);
        intrinsic_name = intrinsic_name + 1) {
      pbVar4 = (byte *)*intrinsic_name;
      pbVar5 = (byte *)(name->text + 1);
      do {
        bVar2 = *pbVar4;
        bVar6 = bVar2 < *pbVar5;
        if (bVar2 != *pbVar5) {
LAB_1044d6a6:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_1044d6ab;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar6 = bVar2 < pbVar5[1];
        if (bVar2 != pbVar5[1]) goto LAB_1044d6a6;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_1044d6ab:
      if (iVar3 == 0) {
        return (int)(intrinsic_name + -0x4132790) >> 2;
      }
    }
  }
  return -1;
}

