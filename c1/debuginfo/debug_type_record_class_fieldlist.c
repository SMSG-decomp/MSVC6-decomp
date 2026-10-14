int __cdecl debug_type_record_class_fieldlist(int pass,c1_symbol *tag,int *count)

{
  char cVar1;
  fe_name *pfVar2;
  char *pcVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  byte bVar8;
  uint uVar9;
  
  puVar4 = g_cv_record_body;
  uVar9 = 0;
  *count = 0;
  if (pass == 2) {
    *puVar4 = 0x1203;
  }
  if (tag->tag_members == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = *(int **)((int)tag->tag_members + 4);
  }
  for (; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[1]) {
    bVar8 = *(byte *)(piVar7 + -2) & 0x1f;
    if ((bVar8 == 4) && ((fe_name *)*piVar7 == g_name_unnamed)) {
      pcVar3 = (char *)piVar7[3];
      cVar1 = *pcVar3;
      while (cVar1 < '\0') {
        pcVar3 = *(char **)(pcVar3 + 4);
        cVar1 = *pcVar3;
      }
      if ((pcVar3[1] & 1U) == 0) goto LAB_106254af;
LAB_106254dc:
      iVar5 = debug_type_record_member
                        (pass,(c1_symbol *)(piVar7 + -2),
                         (ushort *)((uVar9 & 0xffff) + 2 + (int)g_cv_record_body));
      uVar9 = uVar9 + iVar5;
      if (pass == 2) {
        uVar6 = debug_type_pad_to_4((char *)((uVar9 & 0xffff) + 2 + (int)puVar4),(char)uVar9);
        uVar6 = uVar6 & 0xffff;
      }
      else {
        uVar6 = 0;
      }
      uVar9 = uVar9 + uVar6;
      *count = *count + 1;
      if (0xfafd < (uVar9 & 0xffff) + 2) {
        diag_fatal_simple(0x43);
      }
    }
    else {
LAB_106254af:
      pfVar2 = (fe_name *)*piVar7;
      if ((((pfVar2 != (fe_name *)0x0) && (pfVar2 != g_name_unnamed)) &&
          (pfVar2 != g_name_alignment_member)) &&
         (((bVar8 == 0 || (0xe < bVar8)) || ((bVar8 == 5 || (piVar7[3] != 0)))))) goto LAB_106254dc;
    }
    if (piVar7 == (int *)0x0) break;
  }
  if (pass == 2) {
    iVar5 = cvserver_emit_type(uVar9 + 2);
    return iVar5;
  }
  return 0;
}

