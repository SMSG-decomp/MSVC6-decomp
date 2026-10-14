void __thiscall pch_image_init(c1_pch_image *image,int n)

{
  uchar *puVar1;
  
  image->count = n;
  puVar1 = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + n * 4;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  image->segments = (c1_pch_segment **)puVar1;
  image->next_index = 0;
  return;
}

