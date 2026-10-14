c1_pch_segment ** __thiscall pch_image_page_table_new(c1_pch_image *image,void *segment_address)

{
  uchar *table;
  uint size;
  uint base;
  c1_pch_segment *pcVar1;
  int iVar2;
  
  table = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x40000;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  iVar2 = 0;
  if (image->count < 1) {
    return (c1_pch_segment **)table;
  }
  do {
    pcVar1 = image->segments[iVar2];
    size = (*pcVar1->vtbl->pch_segment_size)(pcVar1);
    base = (*segment_address)();
    pcVar1 = (*pcVar1->vtbl->pch_segment_self)(pcVar1);
    pch_page_table_fill((c1_pch_segment **)table,pcVar1,base,size);
    iVar2 = iVar2 + 1;
  } while (iVar2 < image->count);
  return (c1_pch_segment **)table;
}

