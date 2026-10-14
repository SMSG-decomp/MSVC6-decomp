void __thiscall pch_segment_append_to_file(c1_pch_segment *segment,HANDLE file)

{
  DWORD DStack_4;
  
  DStack_4 = 0;
  _g_io_result = GetFileSize(file,&DStack_4);
  segment->file_offset = _g_io_result;
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x57);
  }
  if (DStack_4 != 0) {
    diag_fatal_simple(0x4f);
  }
  segment->file_offset =
       (g_system_info.dwAllocationGranularity - 1) + segment->file_offset &
       ~(g_system_info.dwAllocationGranularity - 1);
  pch_segment_write_bytes(segment,file);
  segment->state = 2;
  return;
}

