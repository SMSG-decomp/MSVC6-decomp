void __cdecl pch_check_defines(void)

{
  byte bVar1;
  c1_vector *pcVar2;
  c1_vector *pcVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  byte *pbVar9;
  bool bVar10;
  short local_8;
  
  pcVar3 = g_define_list;
  local_8 = 0;
LAB_1044a8bc:
  do {
    pcVar2 = PTR_104d1448;
    if ((pcVar3 == (c1_vector *)0x0) || (iVar7 = (int)local_8, (int)(uint)pcVar3->count <= iVar7)) {
      sVar8 = 0;
      while ((pcVar2 != (c1_vector *)0x0 && (iVar7 = (int)sVar8, iVar7 < (int)(uint)pcVar2->count)))
      {
        sVar8 = sVar8 + 1;
        if (*(char *)pcVar2->data[iVar7] != '\0') {
          diag_warning(1,0x28b,pcVar2->data[iVar7]);
        }
      }
      return;
    }
    local_8 = local_8 + 1;
    sVar8 = 0;
    do {
      if ((PTR_104d1448 == (c1_vector *)0x0) ||
         (iVar5 = (int)sVar8, (int)(uint)PTR_104d1448->count <= iVar5)) {
        pp_define_from_switch(pcVar3->data[iVar7]);
        goto LAB_1044a8bc;
      }
      sVar8 = sVar8 + 1;
      pbVar4 = pcVar3->data[iVar7];
      pbVar9 = PTR_104d1448->data[iVar5];
      do {
        bVar1 = *pbVar4;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_1044a8b2:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_1044a87e;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_1044a8b2;
        pbVar4 = pbVar4 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_1044a87e:
    } while (iVar6 != 0);
    *(byte *)PTR_104d1448->data[iVar5] = 0;
  } while( true );
}

