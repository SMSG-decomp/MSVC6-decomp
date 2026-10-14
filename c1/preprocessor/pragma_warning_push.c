void pragma_warning_push(void)

{
  uint uVar1;
  fe_warning_record *pfVar2;
  fe_warning_state *state;
  
  pfVar2 = (fe_warning_record *)g_arenas[0].cur;
  state = g_warning_state;
  if (g_warning_record_free_list == (fe_warning_record *)0x0) {
    g_arenas[0].cur = g_arenas[0].cur + 8;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
  }
  else {
    pfVar2 = g_warning_record_free_list;
    g_warning_record_free_list =
         (fe_warning_record *)(g_warning_record_free_list->next & 0xfffffffe);
  }
  if (pfVar2 == (fe_warning_record *)0x0) {
    state->saved = (fe_warning_record *)0x0;
    return;
  }
  uVar1 = state->level;
  pfVar2->next = (uint)state->saved;
  pfVar2->value = uVar1;
  state->saved = pfVar2;
  return;
}

