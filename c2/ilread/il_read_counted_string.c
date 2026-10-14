short __fastcall il_read_counted_string(char *buf,int max)

{
  char cVar1;
  int16_t iVar2;
  int iVar3;
  FILE *_File;
  int iVar4;
  
  iVar2 = il_read_short();
  iVar4 = (int)iVar2;
  if (iVar4 <= max) {
    _File = g_il_stream;
    if (0 < iVar2) {
      do {
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
        *buf = cVar1;
        buf = buf + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    return iVar2;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\Common\\ioin.c",300);
}

