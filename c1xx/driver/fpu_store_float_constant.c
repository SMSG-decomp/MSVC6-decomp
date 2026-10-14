int __cdecl fpu_store_float_constant(float *value,c1xx_float_const *out)

{
  float fVar1;
  
  fVar1 = *value;
  out->size = 4;
  fpu_store_st0_tbyte_esi((float10)fVar1,(float10 *)out);
  return 0;
}

