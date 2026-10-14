c1xx_pch_stream_reader ** __thiscall
pch_image_page_table_new(c1xx_pch_image *image,void *address_getter)

{
  c1_u8 *page_map;
  uint size;
  uint base;
  c1xx_pch_stream_reader *pcVar1;
  int iVar2;
  
  page_map = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x40000;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  iVar2 = 0;
  if (image->count < 1) {
    return (c1xx_pch_stream_reader **)page_map;
  }
  do {
    pcVar1 = image->segments[iVar2];
    size = (*pcVar1->vtbl->pch_segment_size)(pcVar1);
    base = (*address_getter)();
    pcVar1 = (*pcVar1->vtbl->pch_segment_self)(pcVar1);
    pch_page_table_fill((c1xx_pch_stream_reader **)page_map,pcVar1,base,size);
    iVar2 = iVar2 + 1;
  } while (iVar2 < image->count);
  return (c1xx_pch_stream_reader **)page_map;
}

