void __thiscall pch_segment_append_to_file(c1xx_pch_stream_reader *pch_stream_reader,void *file)

{
  DWORD DStack_4;
  
  DStack_4 = 0;
  _g_io_result = GetFileSize(file,&DStack_4);
  pch_stream_reader->file_offset = _g_io_result;
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x57,0x158,pch_stream_reader->owner->file_name);
  }
  if (DStack_4 == 0) {
    pch_stream_reader->file_offset =
         (g_system_info.dwAllocationGranularity - 1) + pch_stream_reader->file_offset &
         ~(g_system_info.dwAllocationGranularity - 1);
    pch_segment_write_bytes(pch_stream_reader,file);
    pch_stream_reader->state = 2;
    return;
  }
  diag_fatal_simple(0x4f);
}

