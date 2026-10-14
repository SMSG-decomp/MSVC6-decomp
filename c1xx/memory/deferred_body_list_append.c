void __thiscall deferred_body_list_append(c1_deferred_body_list *list,c1_symbol *fn)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[3].cur;
  if (list->first != (c1_deferred_body *)0x0) {
    g_arenas[3].cur = g_arenas[3].cur + 8;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    if (pcVar1 != (c1_u8 *)0x0) {
      pcVar1[4] = '\0';
      pcVar1[5] = '\0';
      pcVar1[6] = '\0';
      pcVar1[7] = '\0';
      *(c1_symbol **)pcVar1 = fn;
      list->cursor->next = (c1_deferred_body *)pcVar1;
      list->cursor = list->cursor->next;
      return;
    }
    list->cursor->next = (c1_deferred_body *)0x0;
    list->cursor = list->cursor->next;
    return;
  }
  g_arenas[3].cur = g_arenas[3].cur + 8;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (pcVar1 != (c1_u8 *)0x0) {
    pcVar1[4] = '\0';
    pcVar1[5] = '\0';
    pcVar1[6] = '\0';
    pcVar1[7] = '\0';
    *(c1_symbol **)pcVar1 = fn;
    list->cursor = (c1_deferred_body *)pcVar1;
    list->first = (c1_deferred_body *)pcVar1;
    return;
  }
  list->cursor = (c1_deferred_body *)0x0;
  list->first = (c1_deferred_body *)0x0;
  return;
}

