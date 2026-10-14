void __fastcall pch_segment_release(c1_pch_segment *segment)

{
  if (segment->address != (c1_u8 *)0x0) {
    if (segment->allocated == '\0') {
      UnmapViewOfFile(segment->block);
    }
    else {
      VirtualFree(segment->address,segment->size,0x4000);
      VirtualFree(segment->address,0,0x8000);
    }
    if (segment->mapping != (HANDLE)0x0) {
      CloseHandle(segment->mapping);
      segment->mapping = (void *)0x0;
    }
    if (segment->file != (HANDLE)0x0) {
      CloseHandle(segment->file);
      segment->file = (void *)0x0;
    }
    segment->block = (c1_u8 *)0x0;
    segment->address = (c1_u8 *)0x0;
    segment->allocated = '\0';
    segment->state = 3;
    return;
  }
  segment->state = 3;
  return;
}

