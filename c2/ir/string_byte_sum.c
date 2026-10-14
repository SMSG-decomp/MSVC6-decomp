int __fastcall string_byte_sum(char *s)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  cVar2 = *s;
  while (cVar2 != '\0') {
    iVar3 = iVar3 + cVar2;
    pcVar1 = s + 1;
    s = s + 1;
    cVar2 = *pcVar1;
  }
  return iVar3;
}

