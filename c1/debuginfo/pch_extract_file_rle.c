void __cdecl pch_extract_file_rle(char *file,int n)

{
  FILE *_File;
  uint _Ch;
  int iVar1;
  uint uVar2;
  
  _File = fopen(file,"wb");
  _g_io_result = (uint)(_File != (FILE *)0x0);
  if (_g_io_result != 1) {
    diag_fatal_file_errno(0x53,0x162,file);
  }
  while (0 < n) {
    g_pch_file->_cnt = g_pch_file->_cnt + -1;
    if (g_pch_file->_cnt < 0) {
      uVar2 = _filbuf(g_pch_file);
    }
    else {
      uVar2 = (uint)(byte)*g_pch_file->_ptr;
      g_pch_file->_ptr = g_pch_file->_ptr + 1;
    }
    if (uVar2 == 0xe5) {
      g_pch_file->_cnt = g_pch_file->_cnt + -1;
      if (g_pch_file->_cnt < 0) {
        uVar2 = _filbuf(g_pch_file);
      }
      else {
        uVar2 = (uint)(byte)*g_pch_file->_ptr;
        g_pch_file->_ptr = g_pch_file->_ptr + 1;
      }
      g_pch_file->_cnt = g_pch_file->_cnt + -1;
      if (g_pch_file->_cnt < 0) {
        _Ch = _filbuf(g_pch_file);
      }
      else {
        _Ch = (uint)(byte)*g_pch_file->_ptr;
        g_pch_file->_ptr = g_pch_file->_ptr + 1;
      }
      n = n + -3;
      if (uVar2 == 0) {
        uVar2 = 0x100;
      }
      if (0 < (int)uVar2) {
        do {
          iVar1 = _File->_cnt + -1;
          _File->_cnt = iVar1;
          if (iVar1 < 0) {
            _flsbuf(_Ch,_File);
          }
          else {
            *_File->_ptr = (char)_Ch;
            _File->_ptr = _File->_ptr + 1;
          }
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
    }
    else {
      iVar1 = _File->_cnt + -1;
      _File->_cnt = iVar1;
      if (iVar1 < 0) {
        _flsbuf(uVar2,_File);
        n = n + -1;
      }
      else {
        *_File->_ptr = (char)uVar2;
        _File->_ptr = _File->_ptr + 1;
        n = n + -1;
      }
    }
  }
  _g_io_result = g_pch_file->_flag & 0x30;
  if (_g_io_result != 0) {
    diag_fatal_file_errno(0x54,0x158,g_pch_file_name);
  }
  _g_io_result = _File->_flag & 0x20;
  if (_g_io_result != 0) {
    diag_fatal_file_errno(0x55,0x162,file);
  }
  _g_io_result = fclose(_File);
  if (_g_io_result != 0) {
    diag_fatal_file_errno(0x52,0x162,file);
  }
  return;
}

