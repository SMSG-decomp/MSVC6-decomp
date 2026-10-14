c1_pch_segment * __cdecl nheap_record_new_4c(c1_pch_segment *tmpl,c1_pch_image *image)

{
  uchar *obj;
  c1_pch_segment *pcVar1;
  
  obj = g_arenas[1].cur;
  if (tmpl->kind == 3) {
    return (c1_pch_segment *)0x0;
  }
  g_arenas[1].cur = g_arenas[1].cur + 0x4c;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (obj != (uchar *)0x0) {
    pcVar1 = nheap_record_init_4c((c1_pch_segment *)obj,tmpl,image);
    return pcVar1;
  }
  return (c1_pch_segment *)0x0;
}

