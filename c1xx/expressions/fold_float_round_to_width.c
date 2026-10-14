int __cdecl fold_float_round_to_width(int out,int width)

{
  int out_00;
  int iVar1;
  double local_8;
  
  out_00 = out;
  if (width == 8) {
    iVar1 = fold_float_to_double_checked((byte *)out,&local_8);
    float_const_set_double(&local_8,(c1xx_float_const *)out_00);
    return iVar1;
  }
  iVar1 = fpu_store_float_if_in_range((float10 *)out,(float *)&out);
  fpu_store_float_constant((float *)&out,(c1xx_float_const *)out_00);
  return iVar1;
}

