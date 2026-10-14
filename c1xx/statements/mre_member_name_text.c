byte * __cdecl mre_member_name_text(void *sym2,int key)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  char *pcVar9;
  
  if (sym2 == g_name_ctor) {
    pbVar3 = (byte *)mre_qualified_name_text((byte *)key);
    return pbVar3;
  }
  if (sym2 == g_name_dtor) {
    g_mre_member_name_text[0] = '~';
    pcVar4 = mre_qualified_name_text((byte *)key);
    uVar6 = 0xffffffff;
    do {
      pcVar9 = pcVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar9 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar9;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pbVar8 = (byte *)(pcVar9 + -uVar6);
    pbVar3 = (byte *)(g_mre_member_name_text + 1);
LAB_10495bd2:
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pbVar3 = *(undefined4 *)pbVar8;
      pbVar8 = pbVar8 + 4;
      pbVar3 = pbVar3 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pbVar3 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      pbVar3 = pbVar3 + 1;
    }
    return (byte *)g_mre_member_name_text;
  }
  if (sym2 == g_name_new) {
    return (byte *)"operator new";
  }
  if (sym2 == g_name_delete) {
    return (byte *)"operator delete";
  }
  if (sym2 == g_name_array_new) {
    return (byte *)"operator new[]";
  }
  if (sym2 == g_name_array_delete) {
    return (byte *)0x104cb1f0;
  }
  pbVar3 = *(byte **)((int)sym2 + 4);
  if ((*pbVar3 != 0x2e) && ((pbVar3[1] == 0 || (pbVar3[2] == 0)))) {
    iVar5 = ispunct((uint)*pbVar3);
    if ((iVar5 != 0) && (*pbVar3 != 0x5f)) {
      uVar6 = 0xffffffff;
      pcVar4 = "operator";
      do {
        pcVar9 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar4 = pcVar9 + -uVar6;
      pcVar9 = g_mre_member_name_text;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar6 = 0xffffffff;
      do {
        pbVar8 = pbVar3;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pbVar8 = pbVar3 + 1;
        bVar2 = *pbVar3;
        pbVar3 = pbVar8;
      } while (bVar2 != 0);
      uVar6 = ~uVar6;
      pbVar8 = pbVar8 + -uVar6;
      iVar5 = -1;
      pcVar4 = g_mre_member_name_text;
      do {
        pcVar9 = pcVar4;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar9 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar9;
      } while (cVar1 != '\0');
      pbVar3 = (byte *)(pcVar9 + -1);
      goto LAB_10495bd2;
    }
  }
  return pbVar3;
}

