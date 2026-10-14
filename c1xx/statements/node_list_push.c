void __cdecl node_list_push(int *head,int value)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_arena *a;
  int *piVar3;
  
  if (((byte)g_compile_flags_cc & 0x10) == 0) {
    pcVar2 = g_arenas[4].cur + 8;
    piVar3 = (int *)g_arenas[4].cur;
    pcVar1 = g_arenas[0].cur;
    if (pcVar2 <= g_arenas[4].end) goto LAB_104a3f9e;
    a = g_arenas + 4;
    g_arenas[4].cur = pcVar2;
  }
  else {
    pcVar1 = g_arenas[0].cur + 8;
    piVar3 = (int *)g_arenas[0].cur;
    pcVar2 = g_arenas[4].cur;
    if (pcVar1 <= g_arenas[0].end) goto LAB_104a3f9e;
    a = g_arenas;
    g_arenas[0].cur = pcVar1;
  }
  arena_grow(a);
  pcVar1 = g_arenas[0].cur;
  pcVar2 = g_arenas[4].cur;
LAB_104a3f9e:
  g_arenas[4].cur = pcVar2;
  g_arenas[0].cur = pcVar1;
  *piVar3 = *head;
  *head = (int)piVar3;
  piVar3[1] = value;
  return;
}

