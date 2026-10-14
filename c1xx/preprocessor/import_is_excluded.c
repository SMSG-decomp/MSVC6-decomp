byte __cdecl import_is_excluded(wchar_t *name,int typekind)

{
  c1_vector *pcVar1;
  byte bVar2;
  int iVar3;
  size_t _MaxCount;
  int iVar4;
  wchar_t **table_2;
  wchar_t **table;
  int iVar5;
  short sVar6;
  int iVar7;
  
  pcVar1 = g_import_excludes;
  if (g_import_excludes != (c1_vector *)0x0) {
    sVar6 = 0;
    while ((pcVar1 != (c1_vector *)0x0 && (iVar3 = (int)sVar6, iVar3 < (int)(uint)pcVar1->count))) {
      sVar6 = sVar6 + 1;
      iVar3 = wcscmp(name,pcVar1->data[iVar3]);
      if (iVar3 == 0) {
        return 1;
      }
    }
  }
  if (g_import_no_auto_exclude == 0) {
    iVar3 = wcsncmp(name,L"__MIDL_",7);
    if (iVar3 == 0) {
      table = g_import_midl_auto_exclude;
      while( true ) {
        _MaxCount = wcslen(*table);
        iVar3 = wcsncmp(name + 7,*table,_MaxCount);
        if (iVar3 == 0) break;
        table = table + 1;
        if (0x104cb3e7 < (int)table) {
          return 0;
        }
      }
LAB_1049b5d9:
      bVar2 = import_exclude_unless_included(name);
      return bVar2;
    }
    iVar3 = 0;
    switch(typekind) {
    case 0:
      table_2 = g_import_auto_exclude_enums;
      iVar7 = 0xb;
      break;
    case 1:
      table_2 = g_import_auto_exclude_records;
      iVar7 = 0x71;
      break;
    default:
      goto switchD_1049b5f6_caseD_2;
    case 3:
    case 4:
      table_2 = g_import_auto_exclude_interfaces;
      iVar7 = 0x8a;
      break;
    case 6:
      table_2 = g_import_auto_exclude_aliases;
      iVar7 = 10;
    }
    do {
      iVar5 = (iVar7 + iVar3) / 2;
      iVar4 = wcscmp(name,table_2[iVar5]);
      if (iVar4 == 0) goto LAB_1049b5d9;
      if (iVar4 < 0) {
        iVar7 = iVar5 + -1;
      }
      else {
        iVar3 = iVar5 + 1;
      }
    } while (iVar3 <= iVar7);
  }
switchD_1049b5f6_caseD_2:
  return 0;
}

