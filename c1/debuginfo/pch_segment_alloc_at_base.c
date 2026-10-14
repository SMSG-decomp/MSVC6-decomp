int __thiscall pch_segment_alloc_at_base(c1_pch_segment *segment,void *file)

{
  c1_u8 *pcVar1;
  
  if (g_opt_BMOVE == '\0') {
    pcVar1 = VirtualAlloc(segment->base,segment->size,0x2000,4);
    segment->address = pcVar1;
    segment->block = pcVar1;
    segment->allocated = '\x01';
  }
  else {
    segment->address = (c1_u8 *)0x0;
    segment->block = (c1_u8 *)0x0;
  }
  if (segment->address != segment->base) {
    if (segment->mapping != (HANDLE)0x0) {
      CloseHandle(segment->mapping);
      segment->mapping = (void *)0x0;
    }
    segment->state = 4;
    return 4;
  }
  segment->state = 6;
  pcVar1 = VirtualAlloc(segment->base,segment->size,0x1000,4);
  if (pcVar1 != segment->base) {
    diag_fatal_simple(0x3c);
  }
  pch_segment_read_bytes(segment,file);
  return segment->state;
}

