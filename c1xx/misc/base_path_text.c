c1_u8 * __cdecl base_path_text(int *path)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  c1_u8 *pcVar8;
  
  iVar6 = 1;
  piVar7 = path;
  if (path == (int *)0x0) {
LAB_104ac7d5:
    pcVar8 = g_arenas[5].cur;
    g_arenas[5].cur = g_arenas[5].cur + (iVar6 + 3U & 0xfffffffc);
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    pcVar8 = pcVar8 + iVar6 + -1;
    *pcVar8 = '\0';
    if (path != (int *)0x0) {
      while( true ) {
        pcVar4 = diag_symbol_display_name((c1_symbol *)path[2]);
        pcVar3 = pcVar4;
        if (*pcVar4 != '\0') {
          do {
            pcVar1 = pcVar3 + 1;
            pcVar3 = pcVar3 + 1;
          } while (*pcVar1 != '\0');
          for (; pcVar3 != pcVar4; pcVar3 = pcVar3 + -1) {
            pcVar8 = pcVar8 + -1;
            *pcVar8 = pcVar3[-1];
          }
        }
        path = (int *)*path;
        if (path == (int *)0x0) break;
        pcVar8[-1] = ':';
        pcVar8 = pcVar8 + -2;
        *pcVar8 = ':';
      }
    }
    return pcVar8;
  }
  do {
    pcVar3 = diag_symbol_display_name((c1_symbol *)piVar7[2]);
    uVar5 = 0xffffffff;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    iVar6 = iVar6 + (~uVar5 - 1);
    if ((int *)*piVar7 == (int *)0x0) goto LAB_104ac7d5;
    iVar6 = iVar6 + 2;
    piVar7 = (int *)*piVar7;
  } while( true );
}

