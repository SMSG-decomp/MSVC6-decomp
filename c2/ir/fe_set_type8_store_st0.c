void __cdecl fe_set_type8_store_st0(double *value,c2_float_const *k)

{
  double dVar1;
  
  dVar1 = *value;
  k->size_tag = 8;
  fpu_store_st0_tbyte_esi(k,(float10)dVar1);
  return;
}

