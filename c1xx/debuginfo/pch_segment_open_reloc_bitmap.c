char __thiscall
pch_segment_open_reloc_bitmap
          (c1xx_pch_stream_reader *pch_stream_reader,c1xx_pch_stream_reader *holder)

{
  c1_u8 *pcVar1;
  c1xx_bitvec *pcVar2;
  
  pcVar1 = pch_stream_reader->saved_bitmap;
  if (pcVar1 != (c1_u8 *)0x0) {
    if ((pcVar1 < holder->saved_end) && (holder->state == 5)) {
      pch_stream_reader->saved_bitmap = pcVar1 + holder->delta;
    }
    pcVar2 = (c1xx_bitvec *)arena_or_heap_object_new(0x20,'\x01',g_arenas + 5);
    if (pcVar2 == (c1xx_bitvec *)0x0) {
      pcVar2 = (c1xx_bitvec *)0x0;
    }
    else {
      pcVar2 = bitvec_init_empty(pcVar2);
    }
    pch_stream_reader->bitmap = pcVar2;
    bitvec_attach(pcVar2,pch_stream_reader->size >> 2,pch_stream_reader->saved_bitmap);
  }
  pch_segment_compute_delta((int)pch_stream_reader);
  return '\x01';
}

