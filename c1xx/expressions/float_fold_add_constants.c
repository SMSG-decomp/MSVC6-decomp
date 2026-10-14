int __cdecl float_fold_add_constants(float10 *a,float10 *b,float10 *out)

{
  float10 fVar1;
  float10 fVar2;
  ushort uVar3;
  int iVar4;
  
  fVar1 = *a;
  fVar2 = *b;
  uVar3 = *(ushort *)((int)a + 10) | *(ushort *)((int)b + 10);
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 8) == 0) {
      *(undefined2 *)((int)out + 10) = 4;
    }
    else {
      *(undefined2 *)((int)out + 10) = 8;
    }
  }
  else {
    *(undefined2 *)((int)out + 10) = 10;
  }
  iVar4 = fpu_store_constant_rounded(fVar2 + fVar1,out);
  return iVar4;
}

