longlong il_read_quad(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  int iVar9;
  FILE *_File;
  
  _File = g_il_stream;
  iVar9 = g_il_stream->_cnt + -1;
  g_il_stream->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar2 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  if (cVar2 != -0x80) {
    return (longlong)(int)cVar2;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar2 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar3 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar3 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar4 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar4 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar5 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar5 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar6 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar6 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar7 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar7 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (iVar9 < 0) {
    iVar9 = _filbuf(_File);
    cVar8 = (char)iVar9;
    _File = g_il_stream;
  }
  else {
    cVar8 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  iVar9 = _File->_cnt + -1;
  _File->_cnt = iVar9;
  if (-1 < iVar9) {
    cVar1 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
    return CONCAT17(cVar1,CONCAT16(cVar8,CONCAT15(cVar7,CONCAT14(cVar6,CONCAT13(cVar5,CONCAT12(cVar4
                                                  ,CONCAT11(cVar3,cVar2)))))));
  }
  iVar9 = _filbuf(_File);
  return CONCAT17((char)iVar9,
                  CONCAT16(cVar8,CONCAT15(cVar7,CONCAT14(cVar6,CONCAT13(cVar5,CONCAT12(cVar4,
                                                  CONCAT11(cVar3,cVar2)))))));
}

