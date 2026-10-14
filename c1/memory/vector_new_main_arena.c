void __fastcall vector_new_main_arena(int *vector)

{
  uchar *puVar1;
  
  vector[2] = 0x400;
  puVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x3000;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *vector = (int)puVar1;
  vector[1] = 0;
  return;
}

