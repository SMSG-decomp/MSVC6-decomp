void __thiscall pch_image_relocate(c1_pch_image *image,int unused)

{
  c1_pch_segment *pcVar1;
  bool bVar2;
  uchar *a;
  char cVar3;
  c1_pch_segment **ppcVar4;
  int iVar5;
  
  ppcVar4 = pch_image_page_table_new(image,pch_segment_vcall_base);
  pcVar1 = image->root;
  bVar2 = false;
  image->saved_page_table = ppcVar4;
  if (pcVar1 == (c1_pch_segment *)0x0) {
    bVar2 = true;
    goto LAB_1064b8d7;
  }
  iVar5 = (*pcVar1->vtbl->pch_segment_map_view)(pcVar1,image->mapping_kept,'\0',(void *)0x0);
  if (iVar5 != 6) {
    iVar5 = (*image->root->vtbl->pch_segment_alloc_anywhere)(image->root,image->file,0);
    if (iVar5 == 5) {
      (*image->root->vtbl->pch_segment_open_reloc_bitmap)(image->root,(c1_pch_segment *)0x0);
    }
  }
  iVar5 = 0;
  if (image->count < 1) {
LAB_1064b8a0:
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
                        (image->segments[iVar5],image->root);
      if (cVar3 == '\0') {
        bVar2 = true;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < image->count);
    if (!bVar2) goto LAB_1064b8a0;
  }
  pcVar1 = image->root;
  if (pcVar1->state == 5) {
    (*pcVar1->vtbl->pch_segment_write_contents)(pcVar1,0);
  }
  (*image->root->vtbl->pch_segment_release)(image->root);
LAB_1064b8d7:
  image->relocation_arena = (fe_arena *)0x0;
  if (bVar2) {
    ppcVar4 = pch_image_page_table_new(image,pch_segment_vcall_loaded_address);
    image->loaded_page_table = ppcVar4;
    a = g_arenas[3].cur;
    g_arenas[3].cur = g_arenas[3].cur + 0x20;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    image->relocation_arena = (fe_arena *)a;
    arena_reserve((fe_arena *)a,g_pch_relocation_arena_desc,(void *)0x0);
    iVar5 = 0;
    if (0 < image->count) {
      do {
        (*image->segments[iVar5]->vtbl->pch_segment_create_reloc_bitmap)
                  (image->segments[iVar5],image->relocation_arena);
        iVar5 = iVar5 + 1;
      } while (iVar5 < image->count);
    }
    pch_fixup_global_roots();
    if (g_abort_requested != 0) {
      c1_abort_if_running();
    }
    pch_relocate_global_tables();
  }
  image->loaded_page_table = (c1_pch_segment **)0x0;
  image->saved_page_table = (c1_pch_segment **)0x0;
  return;
}

