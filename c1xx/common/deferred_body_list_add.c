void __thiscall deferred_body_list_add(c1_deferred_body_list **list_slot,c1_symbol *fn)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[3].cur;
  if (*list_slot == (c1_deferred_body_list *)0x0) {
    g_arenas[3].cur = g_arenas[3].cur + 0xc;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    if (pcVar1 != (c1_u8 *)0x0) {
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1[4] = '\0';
      pcVar1[5] = '\0';
      pcVar1[6] = '\0';
      pcVar1[7] = '\0';
      pcVar1[8] = '\0';
      pcVar1[9] = '\0';
      pcVar1[10] = '\0';
      pcVar1[0xb] = '\0';
      *list_slot = (c1_deferred_body_list *)pcVar1;
      deferred_body_list_append(*list_slot,fn);
      return;
    }
    *list_slot = (c1_deferred_body_list *)0x0;
  }
  deferred_body_list_append(*list_slot,fn);
  return;
}

