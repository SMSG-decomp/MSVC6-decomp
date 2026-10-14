void __cdecl sym_global_helper_set_decorated_name(char unique)

{
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  fe_name *pfVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  uint signature;
  char local_1800 [6140];
  void *chkstk_return;
  
  uVar2 = g_block_scope_number;
  chkstk_return = (void *)0x1064dec4;
  g_block_scope_number = 2;
  pcVar3 = decorate_name(g_line_var_symbol,2);
  if (unique == '\0') {
    pfVar4 = name_intern(pcVar3);
    g_line_var_symbol->name = pfVar4;
    g_block_scope_number = uVar2;
    return;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar8 = pcVar3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar3 = pcVar8 + -uVar5;
  pcVar8 = local_1800;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar3 = local_1800;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar6 = 0xffffffff;
  pcVar3 = g_opt_source_file;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar6 = SigForPbCb(g_opt_source_file,~uVar6 - 1,0xffffffff);
  local_1800[~uVar5 - 1] = '@';
  signature = uVar6;
  iVar7 = 3;
  pcVar3 = local_1800 + ~uVar5;
  do {
    cVar1 = local_1800[iVar7 + -4];
    pcVar8 = pcVar3 + 2;
    iVar7 = iVar7 + -1;
    *pcVar3 = "0123456789abcdef"[(int)cVar1 >> 4 & 0xf];
    pcVar3[1] = "0123456789abcdef"[(int)cVar1 & 0xf];
    pcVar3 = pcVar8;
  } while (-1 < iVar7);
  *pcVar8 = '\0';
  pfVar4 = name_intern(local_1800);
  g_line_var_symbol->name = pfVar4;
  g_block_scope_number = uVar2;
  return;
}

