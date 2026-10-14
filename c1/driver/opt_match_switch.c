int __cdecl opt_match_switch(getflags_row *table,char *word,c1_option_next_fn next_arg,int dup)

{
  uchar uVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  
  bVar4 = true;
  if (word == (char *)0x0) {
    return 0;
  }
  uVar1 = table->kind;
  g_switch_word = word;
joined_r0x10612f1e:
  if (uVar1 == '\0') {
    return 0;
  }
  pcVar8 = table->pattern;
  pcVar9 = word;
LAB_10612f29:
  cVar2 = *pcVar8;
  switch(cVar2) {
  case '\0':
    if (*pcVar9 != '\0') goto LAB_10612f3b;
    if ((table->kind & 0x20) != 0) {
      pcVar9 = (*next_arg)();
      opt_set_switch_value(table,pcVar9,dup);
      uVar7 = 0xffffffff;
      pcVar8 = pcVar9;
      goto code_r0x10613068;
    }
    pcVar9 = (char *)0x0;
    break;
  default:
    goto switchD_10612f55_caseD_1;
  case '#':
    goto switchD_10612f55_caseD_23;
  case '$':
    bVar4 = false;
switchD_10612f55_caseD_23:
    if (*pcVar9 == '\0') {
      pcVar8 = (*next_arg)();
      opt_set_switch_value(table,pcVar8,dup);
      if (!bVar4) goto LAB_10613003;
      uVar7 = 0xffffffff;
      pcVar9 = pcVar8;
      goto code_r0x10613037;
    }
    break;
  case '%':
    bVar4 = false;
    pcVar8 = pcVar8 + 1;
    goto LAB_10612f29;
  case '*':
    if ((*pcVar9 == '\0') || (iVar6 = opt_match_suffix(pcVar8,pcVar9), iVar6 == 0))
    goto LAB_10612f3b;
    break;
  case '-':
    pcVar5 = "-/";
    while (cVar2 = *pcVar5, pcVar5 = pcVar5 + 1, cVar2 != *pcVar9) {
      if (*pcVar5 == '\0') goto LAB_10612f3b;
    }
    pcVar9 = pcVar9 + 1;
    pcVar8 = pcVar8 + 1;
    goto LAB_10612f29;
  }
  opt_set_switch_value(table,pcVar9,dup);
  goto LAB_10612fd5;
  while( true ) {
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    if (cVar2 == '\0') break;
code_r0x10613037:
    if (uVar7 == 0) break;
  }
  g_options_signature = SigForPbCb(pcVar8,~uVar7 - 1,g_options_signature);
  goto LAB_10612fd5;
switchD_10612f55_caseD_1:
  cVar3 = *pcVar9;
  pcVar9 = pcVar9 + 1;
  pcVar8 = pcVar8 + 1;
  if (cVar2 != cVar3) goto LAB_10612f3b;
  goto LAB_10612f29;
LAB_10612f3b:
  uVar1 = table[1].kind;
  table = table + 1;
  goto joined_r0x10612f1e;
  while( true ) {
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar2 == '\0') break;
code_r0x10613068:
    if (uVar7 == 0) break;
  }
  g_options_signature = SigForPbCb(pcVar9,~uVar7 - 1,g_options_signature);
LAB_10612fd5:
  if (bVar4) {
    uVar7 = 0xffffffff;
    pcVar8 = word;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    g_options_signature = SigForPbCb(word,~uVar7 - 1,g_options_signature);
  }
LAB_10613003:
  return (int)(char)table->result;
}

