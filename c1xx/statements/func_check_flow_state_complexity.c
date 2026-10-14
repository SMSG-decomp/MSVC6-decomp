void __cdecl func_check_flow_state_complexity(c1_u8 *record,uint size)

{
  c1_flow_state *pcVar1;
  int iVar2;
  uint uVar3;
  byte size_class;
  c1_flow_state *pcVar4;
  int jmpbuf [16];
  
  if (g_flow_state_abandoned == '\0') {
    if (g_flow_state_depth == -1) {
      if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
        g_flow_error_jmpbuf = jmpbuf;
        iVar2 = _setjmp3(jmpbuf,0);
        if (iVar2 != 0) {
          g_flow_error_jmpbuf = (void *)0x0;
          return;
        }
      }
      pcVar1 = func_flow_state_find(g_flow_state_top,1,'\x01');
      diag_fatal(0x26,pcVar1->subject);
    }
    if (size < 0x11) {
      size_class = 0;
    }
    else if (size < 0x21) {
      size_class = 1;
    }
    else {
      size_class = (0x30 < size) + 2;
    }
    if ((g_flow_state_free_list == (c1_flow_state *)0x0) ||
       (pcVar1 = flow_state_alloc_from_free_list(size_class), pcVar1 == (c1_flow_state *)0x0)) {
      pcVar1 = (c1_flow_state *)g_arenas[4].cur;
      g_flow_state_units_allocated = g_flow_state_units_allocated + 1 + (uint)size_class;
      g_arenas[4].cur = g_arenas[4].cur + (uint)size_class * 0x10 + 0x10;
      if (g_arenas[4].end < g_arenas[4].cur) {
        arena_grow(g_arenas + 4);
      }
    }
    pcVar4 = pcVar1;
    for (uVar3 = size >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar4->kind = *(int *)record;
      record = (c1_u8 *)((int)record + 4);
      pcVar4 = (c1_flow_state *)&pcVar4->flags;
    }
    for (uVar3 = size & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)&pcVar4->kind = (char)*(int *)record;
      record = (c1_u8 *)((int)record + 1);
      pcVar4 = (c1_flow_state *)((int)&pcVar4->kind + 1);
    }
    pcVar4 = pcVar1;
    if (g_flow_state_top != (c1_flow_state *)0x0) {
      g_flow_state_top->next = pcVar1;
      pcVar4 = g_flow_state_bottom;
    }
    g_flow_state_bottom = pcVar4;
    pcVar1->prev = g_flow_state_top;
    g_flow_state_top = pcVar1;
    pcVar1->flags = pcVar1->flags & 0x3f | size_class << 6;
    g_flow_state_top->depth = (c1_u16)g_flow_state_depth;
    g_flow_state_top->next = (c1_flow_state *)0x0;
    g_flow_state_depth = g_flow_state_depth + 1;
  }
  return;
}

