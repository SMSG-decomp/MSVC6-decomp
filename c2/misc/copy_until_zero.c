void copy_until_zero(int *dst,int *src)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *dst;
  piVar2 = dst;
  while (iVar1 != 0) {
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    iVar1 = *piVar2;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  return;
}

