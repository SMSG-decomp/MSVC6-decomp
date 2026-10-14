c1_pch_segment * __thiscall
pch_arena_segment_ctor(c1_pch_segment *segment,fe_arena *a,c1_pch_image *image)

{
  byte bVar1;
  fe_arena_desc *pfVar2;
  c1_u8 *pcVar3;
  uchar *puVar4;
  c1_u32 cVar5;
  
  nheap_object_base_ctor(segment,0,image);
  segment->vtbl = (c1_vtbl_1065b500 *)&PTR_pch_segment_map_view_1065b500;
  pfVar2 = a->desc;
  bVar1 = pfVar2->flags;
  if ((bVar1 & 2) == 0) {
    if ((bVar1 & 4) == 0) {
      segment->kind = 2;
    }
    else {
      segment->kind = 4;
    }
  }
  else {
    segment->kind = 1;
  }
  pcVar3 = a->base;
  segment->base = pcVar3;
  if (pcVar3 == (c1_u8 *)0x0) {
    diag_fatal(1,".\\nheapall.c",0x654);
  }
  cVar5 = (int)a->cur - (int)a->base;
  segment->size = cVar5;
  if (cVar5 == 0) {
    puVar4 = a->cur;
    a->cur = puVar4 + 4;
    if (a->end < puVar4 + 4) {
      arena_grow(a);
    }
    cVar5 = (int)a->cur - (int)a->base;
    segment->size = cVar5;
    if (cVar5 == 0) {
      diag_fatal(1,".\\nheapall.c",0x666);
    }
  }
  segment->saved_bitmap = (void *)0x0;
  segment->file_offset = 0;
  cVar5 = pfVar2->pch_word;
  segment->state = 1;
  segment->descriptor_word = cVar5;
  return segment;
}

