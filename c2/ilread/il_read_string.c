void __fastcall il_read_string(char *buf,int max)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  FILE *_File;
  
  pcVar1 = buf + max;
  _File = g_il_stream;
  do {
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
    *buf = cVar2;
    buf = buf + 1;
  } while (cVar2 != '\0');
  if (buf <= pcVar1) {
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\Common\\ioin.c",0x11b);
}

