int __thiscall pch_segment_alloc_at_base(c1xx_pch_stream_reader *pch_stream_reader,void *file)

{
  c1_u8 *pcVar1;
  
  if (g_opt_BMOVE == '\0') {
    pcVar1 = VirtualAlloc(pch_stream_reader->base,pch_stream_reader->size,0x2000,4);
    pch_stream_reader->address = pcVar1;
    pch_stream_reader->view = pcVar1;
    pch_stream_reader->allocated = '\x01';
  }
  else {
    pch_stream_reader->address = (c1_u8 *)0x0;
    pch_stream_reader->view = (void *)0x0;
  }
  if (pch_stream_reader->address != pch_stream_reader->base) {
    if (pch_stream_reader->mapping != (HANDLE)0x0) {
      CloseHandle(pch_stream_reader->mapping);
      pch_stream_reader->mapping = (void *)0x0;
    }
    pch_stream_reader->state = 4;
    return 4;
  }
  pch_stream_reader->state = 6;
  pcVar1 = VirtualAlloc(pch_stream_reader->base,pch_stream_reader->size,0x1000,4);
  if (pcVar1 != pch_stream_reader->base) {
    diag_fatal_simple(0x3c);
  }
  pch_segment_read_bytes(pch_stream_reader,file);
  return pch_stream_reader->state;
}

