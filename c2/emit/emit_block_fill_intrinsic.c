c2_tuple * __fastcall
emit_block_fill_intrinsic
          (c2_operand *dst,uint32_t a,c2_operand *v,uint32_t b,uint16_t type,uint8_t f,int n,
          c2_tuple *at)

{
  uint16_t v_00;
  uint32_t uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_operand *src;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  c2_const_operand *size;
  uint16_t type_00;
  c2_insert_fn *insert_fn;
  
  v_00 = type;
  pcVar3 = v;
  _type = (uint)type;
  uVar1 = is_loop_invariant_operand(v);
  if (uVar1 == 0) {
    v._0_2_ = 0xac;
    _type = 0x1004;
  }
  else {
    v._0_2_ = 0xad;
  }
  pcVar2 = convert_operand_wrapper(0x2004,(c2_operand *)n,at);
  type_00 = (uint16_t)_type;
  pcVar3 = convert_operand_wrapper(type_00,pcVar3,at);
  src = convert_operand_wrapper(0x1004,dst,at);
  pcVar4 = tuple_new_unary_temp(0x15a,0x2004,pcVar2,tuple_insert_before,at);
  if ((_type & 0xf000) == 0x5000) {
    pcVar2 = operand_new_temp(type_00);
    insert_fn = tuple_insert_before;
    pcVar5 = at;
    size = operand_new_intconst(0x1004,_type & 0xfff,0);
    pcVar5 = tuple_new_blockop(0x16a,type_00,pcVar2,pcVar3,size,insert_fn,pcVar5);
    pcVar2->sym->def = pcVar5;
  }
  else {
    pcVar5 = tuple_new_unary_temp(0x15a,type_00,pcVar3,tuple_insert_before,at);
  }
  pcVar6 = tuple_new_unary_temp(0x15a,0x1004,src,tuple_insert_before,at);
  pcVar4 = tuple_new_intrinsic(400,0x1004,(c2_operand *)0x0,pcVar6->dst,pcVar5->dst,pcVar4->dst,
                               (c2_operand *)0x0,(uint16_t)v,tuple_insert_before,at);
  if ((uint16_t)v == 0xac) {
    pcVar3 = operand_new_memeffect(b);
    tuple_append_src(pcVar4,pcVar3);
  }
  pcVar3 = operand_new_memeffect(a);
  tuple_append_dst(pcVar4,pcVar3);
  tuple_append_int_const(pcVar4,v_00,f);
  return pcVar4;
}

