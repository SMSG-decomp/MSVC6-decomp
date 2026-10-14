void __thiscall pch_arena_record_append(c1_pch_image *image,fe_arena *a)

{
  uchar *segment;
  c1_pch_segment *pcVar1;
  
  segment = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + 0x4c;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (segment == (uchar *)0x0) {
    pcVar1 = (c1_pch_segment *)0x0;
  }
  else {
    pcVar1 = pch_arena_segment_ctor((c1_pch_segment *)segment,a,image);
  }
  image->segments[image->next_index] = pcVar1;
  image->next_index = image->next_index + 1;
  return;
}

