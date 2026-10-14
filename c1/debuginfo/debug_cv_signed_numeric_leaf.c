uint __cdecl debug_cv_signed_numeric_leaf(ushort *out,uint lo,uint hi)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((uint)out >> 0x10);
  if ((((int)hi < 1) && ((((int)hi < 0 || (lo < 0x80)) && (-2 < (int)hi)))) &&
     ((hi < 0x80000000 || (0xffffff7f < lo)))) {
    *out = 0x8000;
    *(char *)(out + 1) = (char)lo;
    return CONCAT22(uVar1,3);
  }
  if ((int)hi < 1) {
    if ((((int)hi < 0) || (lo < 0x8000)) &&
       ((-2 < (int)hi && ((hi < 0x80000000 || (0xffff7fff < lo)))))) {
      *out = 0x8001;
      out[1] = (ushort)lo;
      return CONCAT22(uVar1,4);
    }
    if (((int)hi < 1) &&
       (((((int)hi < 0 || (lo < 0x80000000)) && (-2 < (int)hi)) &&
        ((hi < 0x80000000 || (0x7fffffff < lo)))))) {
      *out = 0x8003;
      *(uint *)(out + 1) = lo;
      return CONCAT22(uVar1,6);
    }
  }
  *(uint *)(out + 1) = lo;
  *(uint *)(out + 3) = hi;
  *out = 0x8009;
  return CONCAT22((short)(hi >> 0x10),10);
}

