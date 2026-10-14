uint il_read_id(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  FILE *_File;
  uint uVar7;
  uint32_t id;
  uint pdb_byte;
  
  _File = g_il_stream;
  if (g_pdb_il_mode == 0) {
    iVar5 = g_il_stream->_cnt + -1;
    g_il_stream->_cnt = iVar5;
    if (iVar5 < 0) {
      iVar5 = _filbuf(_File);
      cVar1 = (char)iVar5;
      _File = g_il_stream;
    }
    else {
      cVar1 = *_File->_ptr;
      _File->_ptr = _File->_ptr + 1;
    }
    iVar5 = _File->_cnt + -1;
    _File->_cnt = iVar5;
    if (iVar5 < 0) {
      uVar6 = _filbuf(_File);
      _File = g_il_stream;
    }
    else {
      uVar6 = (uint)(byte)*_File->_ptr;
      _File->_ptr = _File->_ptr + 1;
    }
    id = (uint32_t)CONCAT11((char)uVar6,cVar1);
    if ((uVar6 & 0x80) != 0) {
      id = CONCAT11((char)uVar6,cVar1) & 0xffff7fff;
      iVar5 = _File->_cnt + -1;
      _File->_cnt = iVar5;
      if (iVar5 < 0) {
        iVar5 = _filbuf(_File);
        cVar1 = (char)iVar5;
        _File = g_il_stream;
      }
      else {
        cVar1 = *_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
      }
      iVar5 = _File->_cnt + -1;
      _File->_cnt = iVar5;
      if (iVar5 < 0) {
        iVar5 = _filbuf(_File);
        cVar2 = (char)iVar5;
      }
      else {
        cVar2 = *_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
      }
      id = id | (uint)CONCAT11(cVar2,cVar1) << 0xf;
    }
    return id;
  }
  iVar5 = g_il_stream->_cnt + -1;
  g_il_stream->_cnt = iVar5;
  if (iVar5 < 0) {
    uVar6 = _filbuf(_File);
    bVar3 = (byte)uVar6;
    pdb_byte = uVar6 & 0xff;
    _File = g_il_stream;
  }
  else {
    bVar3 = *_File->_ptr;
    pdb_byte = (uint)bVar3;
    _File->_ptr = _File->_ptr + 1;
  }
  if ((bVar3 & 0x80) != 0) {
    iVar5 = _File->_cnt + -1;
    _File->_cnt = iVar5;
    if (iVar5 < 0) {
      iVar5 = _filbuf(_File);
      bVar4 = (byte)iVar5;
      _File = g_il_stream;
    }
    else {
      bVar4 = *_File->_ptr;
      _File->_ptr = _File->_ptr + 1;
    }
    uVar6 = bVar3 & 0x3f | (uint)bVar4 << 6;
    if ((bVar3 & 0x40) != 0) {
      iVar5 = _File->_cnt + -1;
      _File->_cnt = iVar5;
      if (-1 < iVar5) {
        pdb_byte = (uint)(byte)*_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
        return pdb_byte << 0xe | uVar6;
      }
      uVar7 = _filbuf(_File);
      pdb_byte = uVar7 & 0xff;
      return pdb_byte << 0xe | uVar6;
    }
    return uVar6;
  }
  return pdb_byte + 0x3fff80;
}

