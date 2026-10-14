void __fastcall yy_copy_token_value(void *dst,void *token)

{
  int iVar1;
  uint *src;
  
  src = (uint *)((int)token + 8);
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(uint *)dst = *src;
    src = src + 1;
    dst = (uint *)((int)dst + 4);
  }
  return;
}

