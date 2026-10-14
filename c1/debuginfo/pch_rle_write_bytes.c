int __cdecl pch_rle_write_bytes(byte *bytes,long n)

{
  uint uVar1;
  
  if (bytes == (byte *)0x0) {
    pch_rle_flush_run();
  }
  else {
    uVar1 = g_pch_rle_byte;
    if (0 < n) {
      do {
        if (*bytes == uVar1) {
          g_pch_rle_run_length = g_pch_rle_run_length + 1;
        }
        else {
          if ((g_pch_rle_run_length == 1) && (uVar1 != 0xe5)) {
            g_pch_file->_cnt = g_pch_file->_cnt + -1;
            if (g_pch_file->_cnt < 0) {
              _flsbuf(g_pch_rle_byte,g_pch_file);
              *g_pch_rle_counter = *g_pch_rle_counter + 1;
            }
            else {
              *g_pch_file->_ptr = (char)g_pch_rle_byte;
              g_pch_file->_ptr = g_pch_file->_ptr + 1;
              *g_pch_rle_counter = *g_pch_rle_counter + 1;
            }
          }
          else {
            pch_rle_flush_run();
          }
          g_pch_rle_run_length = 1;
          uVar1 = (uint)*bytes;
          g_pch_rle_byte = uVar1;
        }
        bytes = bytes + 1;
        n = n + -1;
      } while (n != 0);
    }
  }
  _g_io_result = g_pch_file->_flag & 0x20;
  if (_g_io_result != 0) {
    diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
  }
  return 1;
}

