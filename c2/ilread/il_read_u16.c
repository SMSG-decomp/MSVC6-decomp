ushort il_read_u16(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  FILE *_File;
  
  _File = g_il_stream;
  iVar3 = g_il_stream->_cnt + -1;
  g_il_stream->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (-1 < iVar3) {
    cVar1 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
    return CONCAT11(cVar1,cVar2);
  }
  iVar3 = _filbuf(_File);
  return CONCAT11((char)iVar3,cVar2);
}

