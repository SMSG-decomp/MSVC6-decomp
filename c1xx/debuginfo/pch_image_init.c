void __thiscall pch_image_init(c1xx_pch_image *image,int count)

{
  c1_u8 *pcVar1;
  
  image->count = count;
  pcVar1 = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + count * 4;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  image->segments = (c1xx_pch_stream_reader **)pcVar1;
  image->next_index = 0;
  return;
}

