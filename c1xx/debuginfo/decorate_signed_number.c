char * __cdecl decorate_signed_number(char *out,int value)

{
  char *pcVar1;
  
  if (value < 0) {
    *out = '?';
    out = out + 1;
    value = -value;
  }
  pcVar1 = decorate_number(out,value);
  return pcVar1;
}

