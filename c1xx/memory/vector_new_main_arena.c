void __fastcall vector_new_main_arena(int *v)

{
  c1_u8 *pcVar1;
  
  v[2] = 0x400;
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x3000;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *v = (int)pcVar1;
  v[1] = 0;
  return;
}

