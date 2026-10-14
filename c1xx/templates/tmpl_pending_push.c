void __cdecl tmpl_pending_push(void *item)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[1].cur;
  if (g_compile_phase == 3) {
    g_arenas[1].cur = g_arenas[1].cur + 8;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    *(void **)pcVar1 = item;
    *(c1_diag_note_cell **)(pcVar1 + 4) = g_diag_message_list.context_notes;
    g_diag_message_list.context_notes = (c1_diag_note_cell *)pcVar1;
  }
  return;
}

