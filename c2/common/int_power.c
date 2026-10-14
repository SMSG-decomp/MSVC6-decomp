int __fastcall int_power(int base,int exp)

{
  int iVar1;
  
  iVar1 = 1;
  if (exp < 0) {
    return 0;
  }
  if (0 < exp) {
    do {
      iVar1 = iVar1 * base;
      exp = exp + -1;
    } while (exp != 0);
  }
  return iVar1;
}

