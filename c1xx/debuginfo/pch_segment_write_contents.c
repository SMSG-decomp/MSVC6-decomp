void __thiscall pch_segment_write_contents(c1xx_pch_stream_reader *pch_stream_reader,uint file)

{
  c1_u8 *pcVar1;
  
  pch_stream_reader->base = pch_stream_reader->address;
  if ((pch_stream_reader->bitmap != (c1xx_bitvec *)0x0) &&
     (pch_stream_reader->saved_bitmap == (c1_u8 *)0x0)) {
    pcVar1 = bitvec_release_bits(pch_stream_reader->bitmap);
    pch_stream_reader->saved_bitmap = pcVar1;
  }
  if (pch_stream_reader->kind != 4) {
    pch_segment_write_bytes(pch_stream_reader,(void *)file);
  }
  pch_stream_reader->state = 6;
  if (pch_stream_reader->kind == 1) {
    VirtualProtect(pch_stream_reader->base,pch_stream_reader->size,2,&file);
  }
  return;
}

