char __thiscall pch_segment_open_reloc_bitmap(c1_pch_segment *segment,c1_pch_segment *holder)

{
  c1_u8 *pcVar1;
  fe_bitvec *pfVar2;
  
  pcVar1 = segment->saved_bitmap;
  if (pcVar1 != (c1_u8 *)0x0) {
    if ((pcVar1 < holder->saved_end) && (holder->state == 5)) {
      segment->saved_bitmap = pcVar1 + holder->delta;
    }
    pfVar2 = (fe_bitvec *)arena_or_heap_object_new(0x20,'\x01',g_arenas + 3);
    if (pfVar2 == (fe_bitvec *)0x0) {
      pfVar2 = (fe_bitvec *)0x0;
    }
    else {
      pfVar2 = bitvec_init_empty(pfVar2);
    }
    segment->reloc_bitmap = pfVar2;
    bitvec_attach(pfVar2,segment->size >> 2,segment->saved_bitmap);
  }
  pch_segment_compute_delta(segment);
  return '\x01';
}

