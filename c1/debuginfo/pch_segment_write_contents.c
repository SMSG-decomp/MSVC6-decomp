void __thiscall pch_segment_write_contents(c1_pch_segment *segment,uint file)

{
  c1_u8 *pcVar1;
  
  segment->base = segment->address;
  if ((segment->reloc_bitmap != (fe_bitvec *)0x0) && (segment->saved_bitmap == (void *)0x0)) {
    pcVar1 = bitvec_release_bits(segment->reloc_bitmap);
    segment->saved_bitmap = pcVar1;
  }
  if (segment->kind != 4) {
    pch_segment_write_bytes(segment,(HANDLE)file);
  }
  segment->state = 6;
  if (segment->kind == 1) {
    VirtualProtect(segment->base,segment->size,2,&file);
  }
  return;
}

