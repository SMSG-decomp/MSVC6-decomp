int __fastcall format_integer(uint32_t v,char *out,uint32_t radix)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char local_1f [31];
  
  iVar3 = 0;
  pcVar2 = local_1f;
  if (((int)v < 0) && (radix == 10)) {
    *out = '-';
    out = out + 1;
    v = -v;
    iVar3 = 1;
  }
  do {
    pcVar4 = pcVar2;
    *pcVar4 = g_format_integer_digits[v % radix];
    v = v / radix;
    pcVar2 = pcVar4 + 1;
  } while (v != 0);
  cVar1 = *pcVar4;
  *out = cVar1;
  while (cVar1 != '\0') {
    out = out + 1;
    cVar1 = pcVar4[-1];
    iVar3 = iVar3 + 1;
    pcVar4 = pcVar4 + -1;
    *out = cVar1;
  }
  return iVar3;
}

