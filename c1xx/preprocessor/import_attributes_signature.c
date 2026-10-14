uint __cdecl import_attributes_signature(void *attributes,char *tlb,char *tlh,char *tli)

{
  char cVar1;
  ushort *puVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  short sStack_14;
  uint *attr_entry;
  
  uVar5 = 0xffffffff;
  pcVar7 = tlb;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar5 = SigForPbCb(tlb,~uVar5 - 1,0xffffffff);
  if (g_import_implementation_only == 0) {
    uVar6 = 0xffffffff;
    pcVar7 = tlh;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar5 = SigForPbCb(tlh,~uVar6 - 1,uVar5);
  }
  if (g_import_no_implementation == 0) {
    uVar6 = 0xffffffff;
    pcVar7 = tli;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar5 = SigForPbCb(tli,~uVar6 - 1,uVar5);
  }
  sStack_14 = 0;
  do {
    do {
      if ((attributes == (void *)0x0) ||
         (iVar3 = (int)sStack_14, (int)(uint)*(ushort *)attributes <= iVar3)) {
        return uVar5;
      }
      sStack_14 = sStack_14 + 1;
      attr_entry = *(uint **)(*(int *)((int)attributes + 8) + iVar3 * 4);
      uVar6 = 0xffffffff;
      pcVar7 = (char *)*attr_entry;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar5 = SigForPbCb((char *)*attr_entry,~uVar6 - 1,uVar5);
      puVar2 = (ushort *)attr_entry[1];
    } while (puVar2 == (ushort *)0x0);
    sVar4 = 0;
    while (puVar2 != (ushort *)0x0) {
      iVar3 = (int)sVar4;
      if ((int)(uint)*puVar2 <= iVar3) break;
      sVar4 = sVar4 + 1;
      uVar6 = 0xffffffff;
      pcVar7 = *(char **)(*(int *)(puVar2 + 4) + iVar3 * 4);
      pcVar8 = pcVar7;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar5 = SigForPbCb(pcVar7,~uVar6 - 1,uVar5);
    }
  } while( true );
}

