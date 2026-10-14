ulong __cdecl opt_parse_number_2(char *item)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  ulong uVar5;
  char *_Str;
  
  pcVar2 = item;
  iVar3 = isspace((int)*item);
  _Str = pcVar2;
  while (iVar3 != 0) {
    pcVar1 = _Str + 1;
    _Str = _Str + 1;
    iVar3 = isspace((int)*pcVar1);
  }
  if ((*_Str == '0') && ((_Str[1] == 'x' || (_Str[1] == 'X')))) {
    _Str = _Str + 2;
  }
  piVar4 = _errno();
  *piVar4 = 0;
  iVar3 = isxdigit((int)*_Str);
  if (iVar3 != 0) {
    uVar5 = strtoul(_Str,&item,0x10);
    piVar4 = _errno();
    if (((*piVar4 == 0) && (item != _Str)) && (*item == '\0')) {
      return uVar5;
    }
  }
  diag_fatal(0x31,pcVar2);
}

