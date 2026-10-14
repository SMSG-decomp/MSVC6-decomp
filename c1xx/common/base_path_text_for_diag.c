c1_u8 * __cdecl base_path_text_for_diag(int *path,int with_kinds)

{
  c1_u8 *pcVar1;
  c1_u8 cVar2;
  int *piVar3;
  c1_u8 *pcVar4;
  c1_u8 *pcVar5;
  char *pcVar6;
  c1_u8 *pcVar7;
  
  pcVar4 = g_arenas[5].cur;
  if (with_kinds == 0) {
    pcVar4 = base_path_text(path);
    return pcVar4;
  }
  piVar3 = (int *)*path;
  pcVar1 = g_arenas[5].cur + 0x1800;
  g_arenas[5].cur = pcVar1;
  pcVar7 = pcVar4;
  if (g_arenas[5].end < pcVar1) {
    arena_grow(g_arenas + 5);
  }
  while ((piVar3 != (int *)0x0 && (pcVar7 != pcVar1))) {
    pcVar5 = (c1_u8 *)diag_symbol_display_name((c1_symbol *)piVar3[2]);
    cVar2 = *pcVar5;
    for (; (cVar2 != '\0' && (pcVar7 != pcVar1)); pcVar7 = pcVar7 + 1) {
      *pcVar7 = cVar2;
      cVar2 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    }
    piVar3 = (int *)*piVar3;
    if (piVar3 != (int *)0x0) {
      pcVar6 = "\' of base \'";
      if (*piVar3 == 0) {
        pcVar6 = "\' of class \'";
      }
      cVar2 = *pcVar6;
      for (; (cVar2 != '\0' && (pcVar7 != pcVar1)); pcVar7 = pcVar7 + 1) {
        *pcVar7 = cVar2;
        cVar2 = pcVar6[1];
        pcVar6 = pcVar6 + 1;
      }
    }
    *pcVar7 = '\0';
  }
  return pcVar4;
}

