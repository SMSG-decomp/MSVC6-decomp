short * __cdecl asm_operand_node_new(int value)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  *(int *)(pcVar1 + 4) = value;
  return (short *)pcVar1;
}

