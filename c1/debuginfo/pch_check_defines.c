void pch_check_defines(void)

{
  byte bVar1;
  fe_vector *pfVar2;
  fe_vector *pfVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  short sVar8;
  byte *pbVar9;
  bool bVar10;
  short local_8;
  
  pfVar3 = g_define_list;
  local_8 = 0;
LAB_1063f86a:
  do {
    pfVar2 = PTR_1065d410;
    if ((pfVar3 == (fe_vector *)0x0) || (iVar4 = (int)local_8, (int)(uint)pfVar3->count <= iVar4)) {
      sVar8 = 0;
      while ((pfVar2 != (fe_vector *)0x0 && (iVar4 = (int)sVar8, iVar4 < (int)(uint)pfVar2->count)))
      {
        sVar8 = sVar8 + 1;
        if (*(char *)pfVar2->data[iVar4] != '\0') {
          diag_warning(1,0x28b,pfVar2->data[iVar4]);
        }
      }
      return;
    }
    local_8 = local_8 + 1;
    sVar8 = 0;
    do {
      if ((PTR_1065d410 == (fe_vector *)0x0) ||
         (iVar5 = (int)sVar8, (int)(uint)PTR_1065d410->count <= iVar5)) {
        pp_define_from_switch(pfVar3->data[iVar4]);
        goto LAB_1063f86a;
      }
      sVar8 = sVar8 + 1;
      pbVar6 = pfVar3->data[iVar4];
      pbVar9 = PTR_1065d410->data[iVar5];
      do {
        bVar1 = *pbVar6;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_1063f8e9:
          iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_1063f8da;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_1063f8e9;
        pbVar6 = pbVar6 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar7 = 0;
LAB_1063f8da:
    } while (iVar7 != 0);
    *(byte *)PTR_1065d410->data[iVar5] = 0;
  } while( true );
}

