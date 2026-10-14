int __cdecl fpu_store_float_if_in_range(longdouble *value,float *out)

{
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = fpu_compare_abs();
  if (iVar1 == 0) {
    *out = (float)extraout_ST0;
  }
  return iVar1;
}

