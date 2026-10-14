long __fastcall option_parse_integer(char *text)

{
  uint uVar1;
  int *piVar2;
  long lVar3;
  char *_Str;
  char *local_4;
  
  _Str = text;
  local_4 = text;
  while( true ) {
    if (*(int *)__mb_cur_max_exref < 2) {
      uVar1 = *(byte *)(*(int *)_pctype_exref + *_Str * 2) & 8;
    }
    else {
      uVar1 = _isctype((int)*_Str,8);
    }
    if (uVar1 == 0) break;
    _Str = _Str + 1;
  }
  piVar2 = _errno();
  *piVar2 = 0;
  lVar3 = strtol(_Str,&local_4,0);
  piVar2 = _errno();
  if ((*piVar2 != 0x22) && (*local_4 == '\0')) {
    return lVar3;
  }
  fatal_error(0x31,text);
}

