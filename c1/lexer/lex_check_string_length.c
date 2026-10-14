char * __cdecl lex_check_string_length(char *text,size_t len)

{
  int iVar1;
  wchar_t *_DstCh;
  
  _DstCh = (wchar_t *)((uint)(text + len + 4) & 0xfffffffc);
  if ((wchar_t *)0x1066918f < _DstCh) {
    diag_error(0x1a);
    _DstCh = (wchar_t *)&g_string_literal_buffer;
  }
  iVar1 = mbtowc(_DstCh,text,len);
  if (iVar1 < 0) {
    diag_error(2);
  }
  *text = (char)*_DstCh;
  text[1] = *(char *)((int)_DstCh + 1);
  return text + 2;
}

