void __cdecl fe_set_type4_store_st0_b(float *value,c2_float_const *k)

{
  float fVar1;
  
  fVar1 = *value;
  k->size_tag = 4;
  fpu_store_st0_tbyte_esi(k,(float10)fVar1);
  return;
}

