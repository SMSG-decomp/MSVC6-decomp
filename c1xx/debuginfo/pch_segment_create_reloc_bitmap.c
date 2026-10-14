void __thiscall pch_segment_create_reloc_bitmap(c1xx_pch_stream_reader *pch_stream_reader,int a)

{
  c1xx_bitvec *pcVar1;
  
  if (a != 0) {
    pcVar1 = (c1xx_bitvec *)arena_or_heap_object_new(0x20,'\x01',g_arenas + 5);
    if (pcVar1 == (c1xx_bitvec *)0x0) {
      pcVar1 = (c1xx_bitvec *)0x0;
    }
    else {
      pcVar1 = bitvec_init_empty(pcVar1);
    }
    pch_stream_reader->bitmap = pcVar1;
    bitvec_alloc(pcVar1,pch_stream_reader->size >> 2,(c1_arena *)a);
    pch_segment_compute_delta((int)pch_stream_reader);
    return;
  }
  pch_stream_reader->bitmap = (c1xx_bitvec *)0x0;
  pch_segment_compute_delta((int)pch_stream_reader);
  return;
}

