c1xx_pch_stream_reader * __thiscall
pch_stream_reader_new(c1xx_pch_stream_reader *reader,void *file,int kind,c1xx_pch_image *owner)

{
  char *pcVar1;
  c1xx_pch_image *pcVar2;
  
  pcVar2 = owner;
  nheap_object_base_ctor(reader,kind,owner);
  reader->vtbl = (c1xx_pch_stream_reader_vtbl *)&PTR_pch_segment_map_view_104c4d3c;
  pcVar1 = pcVar2->file_name;
  ReadFile(file,&reader->file_offset,4,(LPDWORD)&owner,(LPOVERLAPPED)0x0);
  if (owner != (c1xx_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  pcVar1 = pcVar2->file_name;
  ReadFile(file,&reader->base,4,(LPDWORD)&owner,(LPOVERLAPPED)0x0);
  if (owner != (c1xx_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  pcVar1 = pcVar2->file_name;
  ReadFile(file,&reader->size,4,(LPDWORD)&owner,(LPOVERLAPPED)0x0);
  if (owner != (c1xx_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  pcVar1 = pcVar2->file_name;
  ReadFile(file,&reader->saved_bitmap,4,(LPDWORD)&owner,(LPOVERLAPPED)0x0);
  if (owner != (c1xx_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  pcVar1 = pcVar2->file_name;
  ReadFile(file,&reader->desc_word,4,(LPDWORD)&owner,(LPOVERLAPPED)0x0);
  if (owner != (c1xx_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  reader->state = 3;
  return reader;
}

