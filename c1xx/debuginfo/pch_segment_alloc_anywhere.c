int __thiscall
pch_segment_alloc_anywhere(c1xx_pch_stream_reader *pch_stream_reader,void *file,int unused)

{
  c1_u8 *pcVar1;
  
  pcVar1 = VirtualAlloc((LPVOID)0x0,pch_stream_reader->size,0x102000,4);
  pch_stream_reader->address = pcVar1;
  pch_stream_reader->allocated = '\x01';
  if (g_opt_BMOVE != '\0') {
    pch_segment_force_relocation(pch_stream_reader);
  }
  if (pch_stream_reader->address == pch_stream_reader->base) {
    pch_stream_reader->state = 6;
  }
  else {
    if (pch_stream_reader->address == (c1_u8 *)0x0) {
      diag_fatal_simple(0x3c);
    }
    pch_stream_reader->state = 5;
  }
  pcVar1 = VirtualAlloc(pch_stream_reader->address,pch_stream_reader->size,0x1000,4);
  if (pcVar1 != pch_stream_reader->address) {
    diag_fatal_simple(0x3c);
  }
  pch_segment_read_bytes(pch_stream_reader,file);
  return pch_stream_reader->state;
}

