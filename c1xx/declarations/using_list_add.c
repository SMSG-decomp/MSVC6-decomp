void __thiscall using_list_add(c1_using_cell **list,c1_namespace_symbol *ns)

{
  c1_using_cell *pcVar1;
  c1_u8 *pcVar2;
  
  pcVar2 = g_arenas[0].cur;
  pcVar1 = *list;
  do {
    if (pcVar1 == (c1_using_cell *)0x0) {
LAB_104931f9:
      g_arenas[0].cur = g_arenas[0].cur + 0xc;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar2 == (c1_u8 *)0x0) {
        *list = (c1_using_cell *)0x0;
        return;
      }
      pcVar1 = *list;
      *(c1_namespace_symbol **)pcVar2 = ns;
      *(c1_using_cell **)(pcVar2 + 4) = pcVar1;
      pcVar2[8] = '\x01';
      pcVar2[9] = '\0';
      pcVar2[10] = '\0';
      pcVar2[0xb] = '\0';
      *list = (c1_using_cell *)pcVar2;
      return;
    }
    if (pcVar1->ns == ns) {
      if (pcVar1 != (c1_using_cell *)0x0) {
        pcVar1->active = pcVar1->active + 1;
        return;
      }
      goto LAB_104931f9;
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

