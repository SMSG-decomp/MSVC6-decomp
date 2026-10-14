void * __cdecl nheap_record_new_4c(void *tmpl,int p2)

{
  c1_u8 *obj;
  c1xx_pch_stream_reader *pcVar1;
  
  obj = g_arenas[1].cur;
  if (*(int *)((int)tmpl + 8) == 3) {
    return (void *)0x0;
  }
  g_arenas[1].cur = g_arenas[1].cur + 0x4c;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (obj != (c1_u8 *)0x0) {
    pcVar1 = nheap_record_init_4c((c1xx_pch_stream_reader *)obj,tmpl,(c1xx_pch_image *)p2);
    return pcVar1;
  }
  return (void *)0x0;
}

