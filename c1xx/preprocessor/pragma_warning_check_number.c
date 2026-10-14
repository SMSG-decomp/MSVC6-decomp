void __cdecl pragma_warning_check_number(uint n,byte state)

{
  char cVar1;
  c1xx_warning_state *pcVar2;
  c1_warning_record *pcVar3;
  uint uVar4;
  
  pcVar3 = (c1_warning_record *)g_arenas[0].cur;
  pcVar2 = g_warning_state;
  uVar4 = n;
  if (4000 < n) {
    uVar4 = n - 4000;
  }
  if ((uVar4 == 0) || (999 < uVar4)) {
    diag_warning(1,0x268,n,0xfa1,4999);
  }
  else {
    if (g_warning_state->saved != (c1_warning_record *)0x0) {
      if (g_warning_record_free_list == (c1_warning_record *)0x0) {
        g_arenas[0].cur = g_arenas[0].cur + 8;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
      }
      else {
        pcVar3 = g_warning_record_free_list;
        g_warning_record_free_list =
             (c1_warning_record *)(g_warning_record_free_list->next & 0xfffffffe);
      }
      if (pcVar3 == (c1_warning_record *)0x0) {
        pcVar3 = (c1_warning_record *)0x0;
      }
      else {
        cVar1 = pcVar2->state[uVar4];
        pcVar3->next = (uint)pcVar2->saved | 1;
        pcVar3->value = (int)cVar1 << 0x1c | uVar4;
      }
      pcVar2->saved = pcVar3;
    }
    pcVar2->state[uVar4] = state;
    if ((699 < uVar4) && (uVar4 < 1000)) {
      if (uVar4 <= g_warning_state_emit_min) {
        g_warning_state_emit_min = uVar4;
      }
      if (g_warning_state_emit_max <= uVar4) {
        g_warning_state_emit_max = uVar4;
        return;
      }
    }
  }
  return;
}

