void __thiscall pch_read_into_buffer(fe_il_buffer *buf,FILE *file,int n)

{
  int _Count;
  int iVar1;
  
  _Count = n;
  if ((n < 0) ||
     (((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + n &&
      (iVar1 = il_buffer_grow(&buf->bytes,n), iVar1 == 0)))) {
    _g_io_result = 0;
  }
  else {
    if (&stack0x00000000 != (undefined1 *)0xfffffff8) {
      n = (int)(buf->bytes).pbEnd;
    }
    if ((buf->bytes).pbStart != (PB)0x0) {
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + _Count;
    }
    _g_io_result = 1;
  }
  if (_g_io_result != 1) {
    diag_fatal_file_errno(0x54,0x158,g_pch_file_name);
  }
  _g_io_result = fread((void *)n,1,_Count,file);
  if (_g_io_result != _Count) {
    diag_fatal_file_errno(0x54,0x158,g_pch_file_name);
  }
  return;
}

