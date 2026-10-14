int il_read_byte(void)

{
  byte bVar1;
  FILE *_File;
  int iVar2;
  
  _File = g_il_stream;
  iVar2 = g_il_stream->_cnt + -1;
  g_il_stream->_cnt = iVar2;
  if (-1 < iVar2) {
    bVar1 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
    return (uint)bVar1;
  }
  iVar2 = _filbuf(_File);
  return iVar2;
}

