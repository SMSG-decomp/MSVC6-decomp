uint32_t il_read_compact_word_file(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  FILE *_File;
  uint32_t value;
  
  _File = g_il_stream;
  iVar3 = g_il_stream->_cnt + -1;
  g_il_stream->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar1 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar1 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    uVar4 = _filbuf(_File);
    _File = g_il_stream;
  }
  else {
    uVar4 = (uint)(byte)*_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  value = (uint32_t)CONCAT11((char)uVar4,cVar1);
  if ((uVar4 & 0x80) != 0) {
    value = CONCAT11((char)uVar4,cVar1) & 0xffff7fff;
    iVar3 = _File->_cnt + -1;
    _File->_cnt = iVar3;
    if (iVar3 < 0) {
      iVar3 = _filbuf(_File);
      cVar1 = (char)iVar3;
      _File = g_il_stream;
    }
    else {
      cVar1 = *_File->_ptr;
      _File->_ptr = _File->_ptr + 1;
    }
    iVar3 = _File->_cnt + -1;
    _File->_cnt = iVar3;
    if (iVar3 < 0) {
      iVar3 = _filbuf(_File);
      cVar2 = (char)iVar3;
    }
    else {
      cVar2 = *_File->_ptr;
      _File->_ptr = _File->_ptr + 1;
    }
    return value | (uint)CONCAT11(cVar2,cVar1) << 0xf;
  }
  return value;
}

