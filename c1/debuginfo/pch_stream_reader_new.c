c1_pch_segment * __thiscall
pch_stream_reader_new(c1_pch_segment *reader,void *file,int kind,uint owner)

{
  nheap_object_base_ctor(reader,kind,(c1_pch_image *)owner);
  reader->vtbl = (c1_vtbl_1065b500 *)&PTR_pch_segment_map_view_1065b500;
  ReadFile(file,&reader->file_offset,4,&owner,(LPOVERLAPPED)0x0);
  if (owner != 4) {
    diag_fatal_file_lasterror(0x54);
  }
  ReadFile(file,&reader->base,4,&owner,(LPOVERLAPPED)0x0);
  if (owner != 4) {
    diag_fatal_file_lasterror(0x54);
  }
  ReadFile(file,&reader->size,4,&owner,(LPOVERLAPPED)0x0);
  if (owner != 4) {
    diag_fatal_file_lasterror(0x54);
  }
  ReadFile(file,&reader->saved_bitmap,4,&owner,(LPOVERLAPPED)0x0);
  if (owner != 4) {
    diag_fatal_file_lasterror(0x54);
  }
  ReadFile(file,&reader->descriptor_word,4,&owner,(LPOVERLAPPED)0x0);
  if (owner != 4) {
    diag_fatal_file_lasterror(0x54);
  }
  reader->state = 3;
  return reader;
}

