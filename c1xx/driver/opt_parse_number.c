long __cdecl opt_parse_number(char *text)

{
  int iVar1;
  long lVar2;
  byte *_Str;
  
  iVar1 = isspace((uint)(byte)*text);
  _Str = (byte *)text;
  while (iVar1 != 0) {
    _Str = _Str + 1;
    iVar1 = isspace((uint)*_Str);
  }
  iVar1 = isdigit((uint)*_Str);
  if (((iVar1 != 0) && (lVar2 = atol((char *)_Str), lVar2 < 0xffff)) && (-1 < lVar2)) {
    return lVar2;
  }
  diag_fatal(0x31,text);
}

