c2_operand * __fastcall constant_convert_to(c2_operand *k,uint16_t type,c2_tuple *user)

{
  ushort uVar1;
  c2_symbol *pcVar2;
  byte bVar3;
  c2_float_const *k_00;
  c2_operand *new_op;
  int iVar4;
  uint32_t uVar5;
  c2_const_operand *new_op_00;
  uint64_t uVar6;
  int32_t int_value;
  float local_8 [2];
  
  uVar1 = k->type;
  bVar3 = (byte)(uVar1 >> 8);
  if (((1 << (byte)(type >> 0xc) & 0xeU) == 0) && ((type & 0xf000) != 0x3000)) {
    if ((1 << (bVar3 >> 4) & 0xeU) != 0) {
      if ((uVar1 & 0xfff) == 8) {
        return (c2_operand *)0x0;
      }
      k_00 = arena_alloc(0,0xc);
      int_value = (k->u18).lo;
      if ((k->type & 0xf000) == 0x1000) {
        fe_set_type4_store_st0(&int_value,k_00);
      }
      else {
        fe_set_type4_store_st0_c((uint32_t *)&int_value,k_00);
      }
      new_op = operand_new_fconst(type,k_00);
      if (user == (c2_tuple *)0x0) {
        node_free((c2_node *)k);
        new_op->type = type;
        return new_op;
      }
      tuple_replace_src(user,k,new_op);
      new_op->type = type;
      return new_op;
    }
    if (g_opt_float_consistency != 0) {
      if (type == uVar1) {
        return k;
      }
      if (type == 0x4004) {
        pcVar2 = k->sym;
        iVar4 = fpu_store_float((c2_float_const *)pcVar2,local_8);
        if (iVar4 != 0) {
          warning(2,0x2f4);
        }
        fe_set_type4_store_st0_b(local_8,(c2_float_const *)pcVar2);
        k->type = 0x4004;
        return k;
      }
    }
  }
  else {
    if (((1 << (bVar3 >> 4) & 0xeU) == 0) && ((uVar1 & 0xf000) != 0x3000)) {
      if ((type & 0xfff) == 8) {
        return (c2_operand *)0x0;
      }
      if ((type & 0xf000) == 0x1000) {
        uVar5 = fpu_store_rounded_int((c2_float_const *)k->sym,&int_value);
      }
      else {
        uVar5 = fpu_store_rounded_int_flags((c2_float_const *)k->sym,(uint16_t *)&int_value);
      }
      if (uVar5 != 0) {
        warning(2,0x2f4);
      }
      new_op_00 = operand_new_intconst(type,int_value,int_value >> 0x1f);
      if (user == (c2_tuple *)0x0) {
        node_free((c2_node *)k);
        new_op_00->type = type;
        return new_op_00;
      }
      tuple_replace_src(user,k,new_op_00);
      new_op_00->type = type;
      return new_op_00;
    }
    uVar5 = k->tag;
    pcVar2 = (c2_symbol *)(k->u18).lo;
    uVar6 = const_normalize(type,(uint32_t)pcVar2,uVar5);
    k->u18 = (c2_operand_u18)(int)uVar6;
    k->tag = (int)(uVar6 >> 0x20);
    if ((pcVar2 != (k->u18).reg) || (uVar5 != (uint32_t)(uVar6 >> 0x20))) {
      k->flags11 = k->flags11 | 0x40;
    }
  }
  k->type = type;
  return k;
}

