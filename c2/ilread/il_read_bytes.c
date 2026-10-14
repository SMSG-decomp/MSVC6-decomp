void __fastcall il_read_bytes(int n,char *out)

{
  char cVar1;
  int iVar2;
  FILE *_File;
  
  _File = g_il_stream;
  if (0 < n) {
    do {
      iVar2 = _File->_cnt + -1;
      _File->_cnt = iVar2;
      if (iVar2 < 0) {
        iVar2 = _filbuf(_File);
        cVar1 = (char)iVar2;
        _File = g_il_stream;
      }
      else {
        cVar1 = *_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
      }
      *out = cVar1;
      out = out + 1;
      n = n + -1;
    } while (n != 0);
  }
  return;
}

