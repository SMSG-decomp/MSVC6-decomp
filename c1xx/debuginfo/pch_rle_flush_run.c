void pch_rle_flush_run(void)

{
  for (; 0xff < g_pch_rle_run_length; g_pch_rle_run_length = g_pch_rle_run_length + -0x100) {
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      _flsbuf(0xe5,(FILE *)g_pch_file);
    }
    else {
      *g_pch_file->_ptr = -0x1b;
      g_pch_file->_ptr = g_pch_file->_ptr + 1;
    }
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      _flsbuf(0,(FILE *)g_pch_file);
    }
    else {
      *g_pch_file->_ptr = '\0';
      g_pch_file->_ptr = g_pch_file->_ptr + 1;
    }
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      _flsbuf(g_pch_rle_byte,(FILE *)g_pch_file);
    }
    else {
      *g_pch_file->_ptr = (char)g_pch_rle_byte;
      g_pch_file->_ptr = g_pch_file->_ptr + 1;
    }
    *g_pch_rle_counter = *g_pch_rle_counter + 3;
  }
  if (g_pch_rle_run_length < 1) {
    return;
  }
  if ((3 < g_pch_rle_run_length) || (g_pch_rle_byte == 0xe5)) {
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      _flsbuf(0xe5,(FILE *)g_pch_file);
    }
    else {
      *g_pch_file->_ptr = -0x1b;
      g_pch_file->_ptr = g_pch_file->_ptr + 1;
    }
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      _flsbuf(g_pch_rle_run_length,(FILE *)g_pch_file);
    }
    else {
      *g_pch_file->_ptr = (char)g_pch_rle_run_length;
      g_pch_file->_ptr = g_pch_file->_ptr + 1;
    }
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      _flsbuf(g_pch_rle_byte,(FILE *)g_pch_file);
      *g_pch_rle_counter = *g_pch_rle_counter + 3;
      return;
    }
    *g_pch_file->_ptr = (char)g_pch_rle_byte;
    g_pch_file->_ptr = g_pch_file->_ptr + 1;
    *g_pch_rle_counter = *g_pch_rle_counter + 3;
    return;
  }
  if (g_pch_rle_run_length != 1) {
    if (g_pch_rle_run_length != 2) {
      if (g_pch_rle_run_length != 3) goto LAB_10454b50;
      g_pch_file->_cnt = g_pch_file->_cnt + -1;
      if (g_pch_file->_cnt < 0) {
        _flsbuf(g_pch_rle_byte,(FILE *)g_pch_file);
      }
      else {
        *g_pch_file->_ptr = (char)g_pch_rle_byte;
        g_pch_file->_ptr = g_pch_file->_ptr + 1;
      }
    }
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      _flsbuf(g_pch_rle_byte,(FILE *)g_pch_file);
    }
    else {
      *g_pch_file->_ptr = (char)g_pch_rle_byte;
      g_pch_file->_ptr = g_pch_file->_ptr + 1;
    }
  }
  g_pch_file->_cnt = g_pch_file->_cnt + -1;
  if (g_pch_file->_cnt < 0) {
    _flsbuf(g_pch_rle_byte,(FILE *)g_pch_file);
  }
  else {
    *g_pch_file->_ptr = (char)g_pch_rle_byte;
    g_pch_file->_ptr = g_pch_file->_ptr + 1;
  }
LAB_10454b50:
  *g_pch_rle_counter = *g_pch_rle_counter + g_pch_rle_run_length;
  return;
}

