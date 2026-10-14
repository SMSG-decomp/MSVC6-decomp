short * __cdecl asm_operand_node_new(int value)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0xc;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  puVar1[0] = '\0';
  puVar1[1] = '\0';
  *(int *)(puVar1 + 4) = value;
  return (short *)puVar1;
}

