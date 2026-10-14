int32_t il_read_long(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  FILE *_File;
  int32_t value;
  
  _File = g_il_stream;
  iVar4 = g_il_stream->_cnt + -1;
  g_il_stream->_cnt = iVar4;
  if (iVar4 < 0) {
    iVar4 = _filbuf(_File);
    cVar1 = (char)iVar4;
    _File = g_il_stream;
  }
  else {
    cVar1 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  if (cVar1 != -0x80) {
    return (int)cVar1;
  }
  iVar4 = _File->_cnt + -1;
  _File->_cnt = iVar4;
  if (iVar4 < 0) {
    iVar4 = _filbuf(_File);
    cVar1 = (char)iVar4;
    _File = g_il_stream;
  }
  else {
    cVar1 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar4 = _File->_cnt + -1;
  _File->_cnt = iVar4;
  if (iVar4 < 0) {
    iVar4 = _filbuf(_File);
    cVar2 = (char)iVar4;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar4 = _File->_cnt + -1;
  _File->_cnt = iVar4;
  if (iVar4 < 0) {
    iVar4 = _filbuf(_File);
    cVar3 = (char)iVar4;
    _File = g_il_stream;
  }
  else {
    cVar3 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  value._0_3_ = CONCAT12(cVar3,CONCAT11(cVar2,cVar1));
  iVar4 = _File->_cnt + -1;
  _File->_cnt = iVar4;
  if (-1 < iVar4) {
    value = CONCAT13(*_File->_ptr,(undefined3)value);
    _File->_ptr = _File->_ptr + 1;
    return value;
  }
  iVar4 = _filbuf(_File);
  value = CONCAT13((char)iVar4,(undefined3)value);
  return value;
}

