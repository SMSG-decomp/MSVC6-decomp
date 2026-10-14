int __thiscall pch_segment_map_view(c1_pch_segment *segment,void *mapping,char keep,void *file)

{
  c1_u8 *pcVar1;
  
  if (g_opt_BMOVE == '\0') {
    pcVar1 = MapViewOfFileEx(mapping,(-(uint)(segment->kind != 2) & 3) + 1,0,segment->file_offset,
                             segment->size,segment->base);
    segment->address = pcVar1;
    segment->block = pcVar1;
  }
  else {
    segment->address = (c1_u8 *)0x0;
    segment->block = (c1_u8 *)0x0;
  }
  if (segment->address == segment->base) {
    segment->state = 6;
    if (keep != '\0') {
      segment->mapping = mapping;
      segment->file = file;
      return segment->state;
    }
  }
  else {
    segment->state = 4;
  }
  return segment->state;
}

