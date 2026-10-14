void __cdecl fe_set_type4_store_st0(int32_t *value,c2_float_const *k)

{
  int iVar1;
  
  iVar1 = *value;
  k->size_tag = 4;
  fpu_store_st0_tbyte_esi(k,(float10)iVar1);
  return;
}

