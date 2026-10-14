wchar_t * __cdecl import_namespace_for_typeinfo(int *buf3,char qualify_own)

{
  int iVar1;
  c1_u8 *pcVar2;
  c1_u8 *item;
  short sVar3;
  c1_u32 *pcVar4;
  c1_u32 *pcVar5;
  c1_u32 *pcVar6;
  bool bVar7;
  c1_u32 *pcVar8;
  int *piStack_20;
  int **ppiStack_1c;
  int **ppiStack_18;
  int *local_10;
  c1_u8 *pcStack_c;
  c1_u32 *pcStack_8;
  
  ppiStack_18 = &local_10;
  ppiStack_1c = &buf3;
  piStack_20 = buf3;
  iVar1 = (**(code **)(*buf3 + 0x48))();
  if (iVar1 < 0) {
    diag_fatal_file(iVar1,0x54,0x166,g_import_file_as_written);
  }
  iVar1 = (**(code **)(*pcStack_8 + 0x1c))(pcStack_8,&piStack_20);
  pcVar8 = pcStack_8;
  if (iVar1 < 0) {
    diag_fatal_file(iVar1,0x54,0x166,g_import_file_as_written);
    pcVar8 = pcStack_8;
  }
  iVar1 = 4;
  bVar7 = true;
  pcVar4 = pcVar8;
  pcVar5 = g_import_libid;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar7 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar7);
  if (bVar7) {
    (**(code **)(*local_10 + 0x30))(local_10,pcVar8);
    (*(code *)(*ppiStack_18)[2])(ppiStack_18);
    if (((char)ppiStack_18 != '\0') && (g_import_no_namespace == 0)) {
      return g_import_namespace;
    }
  }
  else {
    iVar1 = 4;
    bVar7 = true;
    pcVar4 = pcVar8;
    pcVar5 = &g_import_guid_null;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar7 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar1 = 4;
      bVar7 = true;
      pcVar4 = pcVar8;
      pcVar5 = &g_import_libid_stdole;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar7 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (!bVar7) {
        if (g_import_cross_referenced_libs == (c1_vector *)0x0) {
          g_import_cross_referenced_libs = vector_new(0,5);
        }
        else {
          sVar3 = 0;
          while ((g_import_cross_referenced_libs != (c1_vector *)0x0 &&
                 (iVar1 = (int)sVar3, iVar1 < (int)(uint)g_import_cross_referenced_libs->count))) {
            sVar3 = sVar3 + 1;
            ppiStack_1c = (int **)CONCAT22(ppiStack_1c._2_2_,sVar3);
            pcVar4 = g_import_cross_referenced_libs->data[iVar1];
            iVar1 = 4;
            bVar7 = true;
            pcVar5 = pcVar8;
            pcVar6 = pcVar4;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar7 = *pcVar5 == *pcVar6;
              pcVar5 = pcVar5 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            if (bVar7) {
              (**(code **)(*local_10 + 0x30))(local_10,pcVar8);
              (*(code *)(*ppiStack_18)[2])(ppiStack_18);
              return (wchar_t *)pcVar4[8];
            }
          }
        }
        item = g_arenas[5].cur;
        pcVar2 = g_arenas[5].cur + 0x24;
        pcStack_c = g_arenas[5].cur;
        g_arenas[5].cur = pcVar2;
        if (g_arenas[5].end < pcVar2) {
          arena_grow(g_arenas + 5);
        }
        pcVar4 = pcVar8;
        pcVar5 = (c1_u32 *)item;
        for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
          *pcVar5 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        }
        item[0x20] = '\0';
        item[0x21] = '\0';
        item[0x22] = '\0';
        item[0x23] = '\0';
        if (g_imported_libraries != (c1_vector *)0x0) {
          sVar3 = 0;
          do {
            if ((g_imported_libraries == (c1_vector *)0x0) ||
               (iVar1 = (int)sVar3, (int)(uint)g_imported_libraries->count <= iVar1))
            goto LAB_1049ba5d;
            sVar3 = sVar3 + 1;
            bVar7 = true;
            pcVar4 = g_imported_libraries->data[iVar1];
            iVar1 = 4;
            pcVar5 = pcVar8;
            pcVar6 = pcVar4;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar7 = *pcVar5 == *pcVar6;
              pcVar5 = pcVar5 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            item = pcStack_c;
          } while (!bVar7);
          if (((wchar_t *)pcVar4[4] != (wchar_t *)0x0) &&
             (((g_import_no_namespace != 0 || (g_import_namespace == (wchar_t *)0x0)) ||
              (iVar1 = wcscmp((wchar_t *)pcVar4[4],g_import_namespace), item = pcStack_c, iVar1 != 0
              )))) {
            *(c1_u32 *)(pcStack_c + 0x20) = pcVar4[4];
            item = pcStack_c;
          }
        }
LAB_1049ba5d:
        vector_push(g_import_cross_referenced_libs,item);
        (**(code **)(*local_10 + 0x30))(local_10,pcVar8);
        (*(code *)(*ppiStack_18)[2])(ppiStack_18);
        return *(wchar_t **)(item + 0x20);
      }
    }
    (**(code **)(*local_10 + 0x30))(local_10,pcVar8);
    (*(code *)(*ppiStack_18)[2])(ppiStack_18);
  }
  return (wchar_t *)0x0;
}

