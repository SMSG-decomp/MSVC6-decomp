void __cdecl fe_set_type4_store_st0_c(uint32_t *value,c2_float_const *k)

{
  uint uVar1;
  
  uVar1 = *value;
  k->size_tag = 4;
  fpu_store_st0_tbyte_esi(k,(float10)uVar1);
  return;
}

