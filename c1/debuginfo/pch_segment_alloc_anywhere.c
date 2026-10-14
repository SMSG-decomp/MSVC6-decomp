int __thiscall pch_segment_alloc_anywhere(c1_pch_segment *segment,void *file,int unused)

{
  c1_u8 *pcVar1;
  
  pcVar1 = VirtualAlloc((LPVOID)0x0,segment->size,0x102000,4);
  segment->address = pcVar1;
  segment->allocated = '\x01';
  if (g_opt_BMOVE != '\0') {
    pch_segment_force_relocation(segment);
  }
  if (segment->address == segment->base) {
    segment->state = 6;
  }
  else {
    if (segment->address == (c1_u8 *)0x0) {
      diag_fatal_simple(0x3c);
    }
    segment->state = 5;
  }
  pcVar1 = VirtualAlloc(segment->address,segment->size,0x1000,4);
  if (pcVar1 != segment->address) {
    diag_fatal_simple(0x3c);
  }
  pch_segment_read_bytes(segment,file);
  return segment->state;
}

