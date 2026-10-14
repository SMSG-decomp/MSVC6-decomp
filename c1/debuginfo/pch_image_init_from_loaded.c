void __thiscall pch_image_init_from_loaded(c1_pch_image *image,c1_pch_image *loaded,int extra)

{
  uchar *puVar1;
  int iVar2;
  c1_pch_segment *pcVar3;
  
  iVar2 = loaded->count + extra;
  image->count = iVar2;
  puVar1 = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + iVar2 * 4;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  image->segments = (c1_pch_segment **)puVar1;
  image->next_index = 0;
  if (0 < loaded->count) {
    do {
      pcVar3 = nheap_record_new_4c(loaded->segments[image->next_index],image);
      image->segments[image->next_index] = pcVar3;
      iVar2 = image->next_index + 1;
      image->next_index = iVar2;
    } while (iVar2 < loaded->count);
  }
  return;
}

