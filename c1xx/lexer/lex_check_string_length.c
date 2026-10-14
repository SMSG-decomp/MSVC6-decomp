char * __cdecl lex_check_string_length(char *mbchar,size_t mb_len)

{
  int iVar1;
  wchar_t *_DstCh;
  
  _DstCh = (wchar_t *)((uint)(mbchar + mb_len + 4) & 0xfffffffc);
  if ((wchar_t *)0x104de253 < _DstCh) {
    diag_error(0x1a);
    _DstCh = (wchar_t *)&g_string_literal_buffer;
  }
  iVar1 = mbtowc(_DstCh,mbchar,mb_len);
  if (iVar1 < 0) {
    diag_error(2);
  }
  *mbchar = (char)*_DstCh;
  mbchar[1] = *(char *)((int)_DstCh + 1);
  return mbchar + 2;
}

