uint __cdecl pch_check_recorded_entry(uint kind,uint key,char *text,char current_only)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  char *pcVar5;
  bool bVar6;
  
  uVar2 = *g_pch_record_cursor;
  puVar1 = (uint *)g_pch_record_cursor;
  while (uVar2 < 0xd) {
    switch(uVar2) {
    default:
      goto switchD_10488778_caseD_1;
    case 4:
    case 5:
    case 7:
      if ((uVar2 == kind) && (puVar1[2] == key)) {
        iVar3 = (int)(short)puVar1[1];
        bVar6 = true;
        puVar4 = puVar1 + 3;
        pcVar5 = text;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = (char)*puVar4 == *pcVar5;
          puVar4 = (uint *)((int)puVar4 + 1);
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          *puVar1 = 0;
          iVar3 = *g_pch_record_cursor;
          while (iVar3 == 0) {
            g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
            iVar3 = *g_pch_record_cursor;
          }
          return CONCAT31((int3)((uint)g_pch_record_cursor >> 8),1);
        }
      }
    case 0:
    case 8:
      if (current_only != '\0') goto switchD_10488778_caseD_1;
      puVar1 = (uint *)((int)puVar1 + puVar1[1] + 0xc);
      uVar2 = *puVar1;
    }
  }
switchD_10488778_caseD_1:
  return (uint)puVar1 & 0xffffff00;
}

