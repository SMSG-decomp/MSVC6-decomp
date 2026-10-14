long __cdecl opt_parse_number(byte *item)

{
  int iVar1;
  long lVar2;
  byte *_Str;
  
  iVar1 = isspace((uint)*item);
  _Str = item;
  while (iVar1 != 0) {
    _Str = _Str + 1;
    iVar1 = isspace((uint)*_Str);
  }
  iVar1 = isdigit((uint)*_Str);
  if (((iVar1 != 0) && (lVar2 = atol((char *)_Str), lVar2 < 0xffff)) && (-1 < lVar2)) {
    return lVar2;
  }
  diag_fatal(0x31,item);
}

