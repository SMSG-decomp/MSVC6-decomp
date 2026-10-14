int __thiscall
pch_segment_map_view(c1xx_pch_stream_reader *pch_stream_reader,void *mapping,char keep,void *file)

{
  c1_u8 *pcVar1;
  
  if (g_opt_BMOVE == '\0') {
    pcVar1 = MapViewOfFileEx(mapping,(-(uint)(pch_stream_reader->kind != 2) & 3) + 1,0,
                             pch_stream_reader->file_offset,pch_stream_reader->size,
                             pch_stream_reader->base);
    pch_stream_reader->address = pcVar1;
    pch_stream_reader->view = pcVar1;
  }
  else {
    pch_stream_reader->address = (c1_u8 *)0x0;
    pch_stream_reader->view = (void *)0x0;
  }
  if (pch_stream_reader->address == pch_stream_reader->base) {
    pch_stream_reader->state = 6;
    if (keep != '\0') {
      pch_stream_reader->mapping = mapping;
      pch_stream_reader->file = file;
      return pch_stream_reader->state;
    }
  }
  else {
    pch_stream_reader->state = 4;
  }
  return pch_stream_reader->state;
}

