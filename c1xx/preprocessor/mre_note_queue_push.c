void __thiscall mre_note_queue_push(c1_mre_note **pending,int kind,c1_symbol *cls,void *member)

{
  c1_u8 *pcVar1;
  c1_mre_note *head_word;
  
  pcVar1 = g_arenas[5].cur;
  if (*pending == (c1_mre_note *)0x0) {
    g_arenas[5].cur = g_arenas[5].cur + 0x10;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar1 != (c1_u8 *)0x0) {
      *(int *)pcVar1 = kind;
      *(c1_symbol **)(pcVar1 + 4) = cls;
      *(void **)(pcVar1 + 8) = member;
      pcVar1[0xc] = '\0';
      pcVar1[0xd] = '\0';
      pcVar1[0xe] = '\0';
      pcVar1[0xf] = '\0';
      *pending = (c1_mre_note *)pcVar1;
      return;
    }
  }
  else {
    g_arenas[5].cur = g_arenas[5].cur + 0x10;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar1 != (c1_u8 *)0x0) {
      head_word = *pending;
      *(int *)pcVar1 = kind;
      *(c1_symbol **)(pcVar1 + 4) = cls;
      *(void **)(pcVar1 + 8) = member;
      *(c1_mre_note **)(pcVar1 + 0xc) = head_word;
      *pending = (c1_mre_note *)pcVar1;
      return;
    }
  }
  *pending = (c1_mre_note *)0x0;
  return;
}

