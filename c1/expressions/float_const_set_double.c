int __cdecl float_const_set_double(double *value,float_const *out)

{
  double dVar1;
  
  dVar1 = *value;
  out->size = 8;
  fpu_store_st0_tbyte_esi((float10)dVar1,(float10 *)out);
  return 0;
}

