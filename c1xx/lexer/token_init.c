void * __thiscall token_init(void *tok,char code,void *value)

{
  int iVar1;
  uint *dst;
  
  *(char *)tok = code;
  dst = (uint *)((int)tok + 8);
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *(uint *)value;
    value = (uint *)((int)value + 4);
    dst = dst + 1;
  }
  return tok;
}

