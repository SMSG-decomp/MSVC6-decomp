void * __cdecl parse_make_inserted_token_value(void *out,int terminal)

{
  int iVar1;
  uint *src;
  uint *dst;
  uint token_value [6];
  
  if (terminal == 6) {
    token_value[0] = 0;
  }
  else if (terminal == 0x1f) goto LAB_10467fd4;
  token_value[0] = CONCAT31(token_value[0]._1_3_,(char)terminal);
LAB_10467fd4:
  src = token_value;
  dst = out;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  return out;
}

