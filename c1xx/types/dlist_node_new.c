c1_dlist_node * __cdecl dlist_node_new(c1_dlist_node *next,c1_dlist_node *prev)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (next == (c1_dlist_node *)0x0) {
    next = (c1_dlist_node *)pcVar1;
  }
  *(c1_dlist_node **)(pcVar1 + 4) = next;
  if (prev != (c1_dlist_node *)0x0) {
    *(c1_dlist_node **)(pcVar1 + 8) = prev;
    return (c1_dlist_node *)pcVar1;
  }
  *(c1_u8 **)(pcVar1 + 8) = pcVar1;
  return (c1_dlist_node *)pcVar1;
}

