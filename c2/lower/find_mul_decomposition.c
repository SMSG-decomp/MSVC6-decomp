c2_mul_decomp * __fastcall find_mul_decomposition(int n,int budget)

{
  c2_mul_decomp *best;
  int iVar1;
  uint uVar2;
  int iVar3;
  
  best = mul_decomp_lookup(n);
  if ((best->from == (c2_mul_decomp *)0x0) && (best->cost == 500)) {
    best->cost = budget;
    uVar2 = 8;
    if (n < 1) {
      do {
        if ((n <= (int)uVar2) && (n % (int)(uVar2 + 1) == 0)) {
          switch(uVar2) {
          case 2:
            iVar1 = 9;
            break;
          case 3:
            iVar1 = 10;
            break;
          default:
            iVar1 = 0xb;
          }
          try_mul_decomposition_step(n / (int)(uVar2 + 1),best,iVar1);
        }
        uVar2 = (int)uVar2 >> 1;
      } while (1 < uVar2);
      iVar3 = 4;
      iVar1 = 1 - n;
    }
    else {
      do {
        if (((int)uVar2 <= n) && (n % (int)(uVar2 + 1) == 0)) {
          switch(uVar2) {
          case 2:
            iVar1 = 9;
            break;
          case 3:
            iVar1 = 10;
            break;
          default:
            iVar1 = 0xb;
          }
          try_mul_decomposition_step(n / (int)(uVar2 + 1),best,iVar1);
        }
        uVar2 = (int)uVar2 >> 1;
      } while (1 < uVar2);
      iVar3 = 2;
      iVar1 = n + -1;
    }
    iVar1 = odd_part(iVar1);
    try_mul_decomposition_step(iVar1,best,iVar3);
    iVar3 = 3;
    iVar1 = odd_part(n + 1);
    try_mul_decomposition_step(iVar1,best,iVar3);
  }
  return best;
}

