ushort __cdecl debug_cv_unsigned_numeric_leaf(ushort *out,uint lo,int hi)

{
  if ((hi == 0) && (lo < 0x8000)) {
    *out = (ushort)lo;
    return 2;
  }
  if (hi != 0) {
    *(uint *)(out + 1) = lo;
    *out = 0x800a;
    *(int *)(out + 3) = hi;
    return 10;
  }
  if (0xffff < lo) {
    *out = 0x8004;
    *(uint *)(out + 1) = lo;
    return 6;
  }
  *out = 0x8002;
  out[1] = (ushort)lo;
  return 4;
}

