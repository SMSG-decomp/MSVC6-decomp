int __cdecl pp_if_parse_defined(int name)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  bool bVar7;
  short n;
  
  pbVar2 = *(byte **)(name + 4);
  uVar6 = 0;
  iVar4 = 0;
  pcVar5 = "defined";
  do {
    bVar1 = *pbVar2;
    bVar7 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_1044e141:
      iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_1044e05e;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar7 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) goto LAB_1044e141;
    pbVar2 = pbVar2 + 2;
    pcVar5 = pcVar5 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_1044e05e:
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = pp_skip_blanks_in_macro_text();
  if ((iVar3 == 0) && (g_macro_rescan_level == 0)) {
    return 0;
  }
  if (*g_input_ptr == 0x28) {
    iVar4 = 1;
    g_input_ptr = g_input_ptr + 1;
    iVar3 = pp_skip_blanks_in_macro_text();
    if ((iVar3 == 0) && (g_macro_rescan_level == 0)) {
      return 0;
    }
  }
  bVar1 = *g_input_ptr;
  name = CONCAT31(name._1_3_,bVar1);
  if (g_macro_rescan_level < 1) {
    if ((g_char_flags[bVar1] & 1) == 0) {
      if (iVar4 == 0) {
        n = 3;
      }
      else {
        n = 4;
      }
      diag_error(n);
      goto LAB_1044e0f5;
    }
    g_input_ptr = g_input_ptr + 1;
    lex_scan_identifier(bVar1);
  }
  else {
    if ((g_char_class[bVar1] != '&') && ((g_char_flags[bVar1] & 1) == 0)) goto LAB_1044e0f5;
    g_input_ptr = g_input_ptr + 1;
    pp_macro_scan_identifier(name);
  }
  uVar6 = (uint)(g_last_name->macro != (fe_macro *)0x0);
LAB_1044e0f5:
  if ((((g_char_class[*g_input_ptr] != '\x01') && (g_char_class[*g_input_ptr] != '\0')) ||
      (iVar3 = pp_skip_blanks_in_macro_text(), iVar3 != 0)) && (iVar4 != 0)) {
    if (*g_input_ptr == 0x29) {
      g_input_ptr = g_input_ptr + 1;
      iVar4 = iVar4 + -1;
    }
    if ((0 < iVar4) && (g_macro_rescan_level == 0)) {
      diag_warning(1,4);
    }
  }
  return uVar6;
}

