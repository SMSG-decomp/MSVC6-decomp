void __fastcall il_read_compact_qword_file(int32_t *lo,int32_t *hi)

{
  char *pcVar1;
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
  if (cVar2 != -0x80) {
    *lo = (int)cVar2;
    *hi = (-1 < cVar2) - 1;
    return;
  }
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  *(char *)lo = cVar2;
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  *(char *)((int)lo + 1) = cVar2;
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  *(char *)((int)lo + 2) = cVar2;
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  *(char *)((int)lo + 3) = cVar2;
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  *(char *)hi = cVar2;
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  *(char *)((int)hi + 1) = cVar2;
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (iVar3 < 0) {
    iVar3 = _filbuf(_File);
    cVar2 = (char)iVar3;
    _File = g_il_stream;
  }
  else {
    cVar2 = *_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  *(char *)((int)hi + 2) = cVar2;
  iVar3 = _File->_cnt + -1;
  _File->_cnt = iVar3;
  if (-1 < iVar3) {
    pcVar1 = _File->_ptr;
    *(char *)((int)hi + 3) = *pcVar1;
    _File->_ptr = pcVar1 + 1;
    return;
  }
  iVar3 = _filbuf(_File);
  *(char *)((int)hi + 3) = (char)iVar3;
  return;
}

