void __thiscall pch_read_into_buffer(c1_il_buffer *buf,void *f,int n)

{
  int _Count;
  int iVar1;
  
  _Count = n;
  if ((n < 0) ||
     (((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + n &&
      (iVar1 = il_buffer_grow(&buf->bytes,n), iVar1 == 0)))) {
    _g_io_result = 0;
  }
  else {
    if (&stack0x00000000 != (undefined1 *)0xfffffff8) {
      n = (int)(buf->bytes).cur;
    }
    if ((buf->bytes).start != (c1_u8 *)0x0) {
      (buf->bytes).cur = (buf->bytes).cur + _Count;
    }
    _g_io_result = 1;
  }
  if (_g_io_result != 1) {
    diag_fatal_file_errno(0x54,0x158,g_pch_file_name);
  }
  _g_io_result = fread((void *)n,1,_Count,f);
  if (_g_io_result != _Count) {
    diag_fatal_file_errno(0x54,0x158,g_pch_file_name);
  }
  return;
}

