void __fastcall pch_segment_compute_delta(c1_pch_segment *segment)

{
  int iVar1;
  c1_u8 *pcVar2;
  
  iVar1 = (int)segment->address - (int)segment->base;
  pcVar2 = segment->base + segment->size;
  segment->saved_end = pcVar2;
  segment->delta = iVar1;
  segment->loaded_end = pcVar2 + iVar1;
  return;
}

