void __cdecl pragma_warning_check_number(uint n,byte state)

{
  char cVar1;
  fe_warning_state *pfVar2;
  fe_warning_record *pfVar3;
  uint uVar4;
  
  pfVar3 = (fe_warning_record *)g_arenas[0].cur;
  pfVar2 = g_warning_state;
  uVar4 = n;
  if (4000 < n) {
    uVar4 = n - 4000;
  }
  if ((uVar4 == 0) || (999 < uVar4)) {
    diag_warning(1,0x268,n,0xfa1,4999);
  }
  else {
    if (g_warning_state->saved != (fe_warning_record *)0x0) {
      if (g_warning_record_free_list == (fe_warning_record *)0x0) {
        g_arenas[0].cur = g_arenas[0].cur + 8;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
      }
      else {
        pfVar3 = g_warning_record_free_list;
        g_warning_record_free_list =
             (fe_warning_record *)(g_warning_record_free_list->next & 0xfffffffe);
      }
      if (pfVar3 == (fe_warning_record *)0x0) {
        pfVar3 = (fe_warning_record *)0x0;
      }
      else {
        cVar1 = pfVar2->state[uVar4];
        pfVar3->next = (uint)pfVar2->saved | 1;
        pfVar3->value = (int)cVar1 << 0x1c | uVar4;
      }
      pfVar2->saved = pfVar3;
    }
    pfVar2->state[uVar4] = state;
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

