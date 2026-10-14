int __cdecl float_const_compare_mask(ushort mask,void *a,void *b)

{
  float10 fVar1;
  float10 fVar2;
  ushort uVar3;
  
  fVar1 = *(float10 *)a;
  fVar2 = *(float10 *)b;
  g_fpu_status_word =
       (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
       (ushort)(fVar1 == fVar2) << 0xe;
  if ((fVar1 == fVar2) == 0) {
    if (fVar1 < fVar2) {
      uVar3 = 4;
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 1;
  }
  return (uint)((uVar3 & mask) != 0);
}

