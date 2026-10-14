void __fastcall diag_queue_release_pending(int *queue)

{
  int iVar1;
  c1_u8 *pcVar2;
  uint value;
  uint *cell;
  
  iVar1 = queue[5];
  while (iVar1 != 0) {
    cell = (uint *)queue[5];
    if (cell == (uint *)0x0) {
      value = 0;
    }
    else {
      queue[5] = cell[1];
      value = *cell;
    }
    if (queue[5] == 0) {
      queue[6] = 0;
    }
    pcVar2 = g_arenas[9].cur;
    g_arenas[9].cur = g_arenas[9].cur + 8;
    if (g_arenas[9].end < g_arenas[9].cur) {
      arena_grow(g_arenas + 9);
    }
    *(uint *)pcVar2 = value;
    pcVar2[4] = '\0';
    pcVar2[5] = '\0';
    pcVar2[6] = '\0';
    pcVar2[7] = '\0';
    if (queue[1] != 0) {
      *(c1_u8 **)(queue[1] + 4) = pcVar2;
    }
    queue[1] = (int)pcVar2;
    if (*queue == 0) {
      *queue = (int)pcVar2;
    }
    diag_queue_print((c1_diag_context *)queue);
    iVar1 = queue[5];
  }
  return;
}

