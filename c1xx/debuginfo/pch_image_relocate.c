void __thiscall pch_image_relocate(c1xx_pch_image *image,int unused)

{
  c1xx_pch_stream_reader *pcVar1;
  bool bVar2;
  c1_u8 *a;
  char cVar3;
  c1xx_pch_stream_reader **ppcVar4;
  int iVar5;
  
  ppcVar4 = pch_image_page_table_new(image,pch_segment_vcall_base);
  pcVar1 = image->bitmap_segment;
  bVar2 = false;
  image->saved_page_map = ppcVar4;
  if (pcVar1 == (c1xx_pch_stream_reader *)0x0) {
    bVar2 = true;
    goto LAB_10495329;
  }
  iVar5 = (*pcVar1->vtbl->pch_segment_map_view)(pcVar1,image->mapping_to_close,'\0',(void *)0x0);
  if (iVar5 != 6) {
    iVar5 = (*image->bitmap_segment->vtbl->pch_segment_alloc_anywhere)
                      (image->bitmap_segment,image->file,0);
    if (iVar5 == 5) {
      (*image->bitmap_segment->vtbl->pch_segment_open_reloc_bitmap)
                (image->bitmap_segment,(c1xx_pch_stream_reader *)0x0);
    }
  }
  iVar5 = 0;
  if (image->count < 1) {
LAB_104952f2:
    pch_fixup_global_roots();
    iVar5 = 0;
    if (0 < image->count) {
      do {
        (*image->segments[iVar5]->vtbl->pch_segment_apply_relocations)(image->segments[iVar5],image)
        ;
        iVar5 = iVar5 + 1;
      } while (iVar5 < image->count);
    }
  }
  else {
    do {
      cVar3 = (*image->segments[iVar5]->vtbl->pch_segment_open_reloc_bitmap)
                        (image->segments[iVar5],image->bitmap_segment);
      if (cVar3 == '\0') {
        bVar2 = true;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < image->count);
    if (!bVar2) goto LAB_104952f2;
  }
  pcVar1 = image->bitmap_segment;
  if (pcVar1->state == 5) {
    (*pcVar1->vtbl->pch_segment_write_contents)(pcVar1,0);
  }
  (*image->bitmap_segment->vtbl->pch_segment_release)(image->bitmap_segment);
LAB_10495329:
  image->arena = (c1_arena *)0x0;
  if (bVar2) {
    ppcVar4 = pch_image_page_table_new(image,pch_segment_vcall_loaded_address);
    image->loaded_page_map = ppcVar4;
    a = g_arenas[5].cur;
    g_arenas[5].cur = g_arenas[5].cur + 0x20;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    image->arena = (c1_arena *)a;
    arena_reserve((c1_arena *)a,&g_pch_relocation_arena_desc,(void *)0x0);
    iVar5 = 0;
    if (0 < image->count) {
      do {
        (*image->segments[iVar5]->vtbl->pch_segment_create_reloc_bitmap)
                  (image->segments[iVar5],(int)image->arena);
        iVar5 = iVar5 + 1;
      } while (iVar5 < image->count);
    }
    pch_fixup_global_roots();
    if (g_abort_requested != 0) {
      c1xx_abort_if_running();
    }
    pch_relocate_global_tables();
  }
  image->loaded_page_map = (c1xx_pch_stream_reader **)0x0;
  image->saved_page_map = (c1xx_pch_stream_reader **)0x0;
  return;
}

