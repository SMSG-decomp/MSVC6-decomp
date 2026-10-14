void __thiscall pch_segment_create_reloc_bitmap(c1_pch_segment *segment,fe_arena *a)

{
  fe_bitvec *pfVar1;
  
  if (a != (fe_arena *)0x0) {
    pfVar1 = (fe_bitvec *)arena_or_heap_object_new(0x20,'\x01',g_arenas + 3);
    if (pfVar1 == (fe_bitvec *)0x0) {
      pfVar1 = (fe_bitvec *)0x0;
    }
    else {
      pfVar1 = bitvec_init_empty(pfVar1);
    }
    segment->reloc_bitmap = pfVar1;
    bitvec_alloc(pfVar1,segment->size >> 2,a);
    pch_segment_compute_delta(segment);
    return;
  }
  segment->reloc_bitmap = (void *)0x0;
  pch_segment_compute_delta(segment);
  return;
}

