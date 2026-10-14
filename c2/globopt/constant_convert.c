c2_operand * __fastcall constant_convert(uint32_t type,c2_operand *k)

{
  uint32_t hi;
  c2_symbol *lo;
  c2_float_const *k_00;
  c2_operand *pcVar1;
  uint16_t type_00;
  uint64_t uVar2;
  int32_t int_value;
  
  type_00 = (uint16_t)type;
  int_value = type;
  if ((1 << (sbyte)((type & 0xffff) >> 0xc) & 0xeU) != 0) {
    hi = k->tag;
    lo = (c2_symbol *)(k->u18).lo;
    uVar2 = const_normalize(type_00,(uint32_t)lo,hi);
    k->u18 = (c2_operand_u18)(int)uVar2;
    k->tag = (int)(uVar2 >> 0x20);
    if ((lo != (k->u18).reg) || (hi != (uint32_t)(uVar2 >> 0x20))) {
      k->flags11 = k->flags11 | 0x40;
    }
    k->type = type_00;
    return k;
  }
  k_00 = arena_alloc(0,0xc);
  int_value = (k->u18).lo;
  if ((k->type & 0xf000) == 0x1000) {
    constant_convert(0x1004,k);
    fe_set_type4_store_st0(&int_value,k_00);
  }
  else {
    constant_convert(0x2004,k);
    fe_set_type4_store_st0_c((uint32_t *)&int_value,k_00);
  }
  pcVar1 = operand_new_fconst(type_00,k_00);
  pcVar1->type = type_00;
  return pcVar1;
}

