void __fastcall pch_segment_release(c1xx_pch_stream_reader *pch_stream_reader)

{
  if (pch_stream_reader->address != (c1_u8 *)0x0) {
    if (pch_stream_reader->allocated == '\0') {
      UnmapViewOfFile(pch_stream_reader->view);
    }
    else {
      VirtualFree(pch_stream_reader->address,pch_stream_reader->size,0x4000);
      VirtualFree(pch_stream_reader->address,0,0x8000);
    }
    if (pch_stream_reader->mapping != (HANDLE)0x0) {
      CloseHandle(pch_stream_reader->mapping);
      pch_stream_reader->mapping = (void *)0x0;
    }
    if (pch_stream_reader->file != (HANDLE)0x0) {
      CloseHandle(pch_stream_reader->file);
      pch_stream_reader->file = (void *)0x0;
    }
    pch_stream_reader->view = (void *)0x0;
    pch_stream_reader->address = (c1_u8 *)0x0;
    pch_stream_reader->allocated = '\0';
    pch_stream_reader->state = 3;
    return;
  }
  pch_stream_reader->state = 3;
  return;
}

