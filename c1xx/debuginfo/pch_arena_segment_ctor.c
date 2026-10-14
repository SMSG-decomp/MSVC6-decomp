c1xx_pch_stream_reader * __thiscall
pch_arena_segment_ctor(c1xx_pch_stream_reader *segment,c1_arena *a,c1xx_pch_image *owner)

{
  byte bVar1;
  c1_arena_desc *pcVar2;
  c1_u8 *pcVar3;
  uint value;
  uint value_2;
  uint value_3;
  
  nheap_object_base_ctor(segment,0,owner);
  segment->vtbl = (c1xx_pch_stream_reader_vtbl *)&PTR_pch_segment_map_view_104c4d3c;
  pcVar2 = a->desc;
  bVar1 = pcVar2->flags;
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
  if (pcVar3 != (c1_u8 *)0x0) {
    value = (int)a->cur - (int)a->base;
    segment->size = value;
    if (value == 0) {
      pcVar3 = a->cur;
      a->cur = pcVar3 + 4;
      if (a->end < pcVar3 + 4) {
        arena_grow(a);
      }
      value_2 = (int)a->cur - (int)a->base;
      segment->size = value_2;
      if (value_2 == 0) {
        diag_fatal(1,".\\nheapall.c",0x666);
      }
    }
    segment->saved_bitmap = (c1_u8 *)0x0;
    segment->file_offset = 0;
    value_3 = pcVar2->pch_word;
    segment->state = 1;
    segment->desc_word = value_3;
    return segment;
  }
  diag_fatal(1,".\\nheapall.c",0x654);
}

