int __cdecl fold_float_round_to_width(float_const *value,int width)

{
  float_const *out;
  int iVar1;
  double local_8;
  
  out = value;
  if (width == 8) {
    iVar1 = fold_float_to_double_checked((float10 *)value,&local_8);
    float_const_set_double(&local_8,out);
    return iVar1;
  }
  iVar1 = fpu_store_float_if_in_range((longdouble *)value,(float *)&value);
  fpu_store_float_constant((float *)&value,out);
  return iVar1;
}

