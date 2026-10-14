int * __cdecl tree_copy_node_cell_list_list(int *list,int arena)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  int *piVar3;
  c1_arena *a;
  int *piVar4;
  
  if (arena == 10) {
    if (((byte)g_compile_flags_cc & 0x10) == 0) {
      pcVar2 = g_arenas[4].cur + 8;
      piVar4 = (int *)g_arenas[4].cur;
      pcVar1 = g_arenas[0].cur;
      if (pcVar2 <= g_arenas[4].end) goto LAB_1047f4f6;
      a = g_arenas + 4;
      g_arenas[4].cur = pcVar2;
    }
    else {
      pcVar1 = g_arenas[0].cur + 8;
      piVar4 = (int *)g_arenas[0].cur;
      pcVar2 = g_arenas[4].cur;
      if (pcVar1 <= g_arenas[0].end) goto LAB_1047f4f6;
      a = g_arenas;
      g_arenas[0].cur = pcVar1;
    }
  }
  else {
    a = g_arenas + arena;
    piVar4 = (int *)a->cur;
    piVar3 = (int *)g_arenas[arena].end;
    a->cur = (c1_u8 *)(piVar4 + 2);
    pcVar1 = g_arenas[0].cur;
    pcVar2 = g_arenas[4].cur;
    if (piVar4 + 2 <= piVar3) goto LAB_1047f4f6;
  }
  arena_grow(a);
  pcVar1 = g_arenas[0].cur;
  pcVar2 = g_arenas[4].cur;
LAB_1047f4f6:
  g_arenas[4].cur = pcVar2;
  g_arenas[0].cur = pcVar1;
  *piVar4 = *list;
  piVar4[1] = list[1];
  if (*piVar4 != 0) {
    piVar3 = tree_copy_node_cell_list_list((int *)*list,arena);
    *piVar4 = (int)piVar3;
  }
  piVar3 = tree_copy_node_cell_list((int *)list[1],arena);
  piVar4[1] = (int)piVar3;
  return piVar4;
}

