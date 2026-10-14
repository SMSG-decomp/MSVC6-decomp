c2_operand * __fastcall
lower_block_fill_value(c2_tuple *t,c2_operand *val,int elem_size,uint32_t count,c2_symbol *reg)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *op;
  c2_tuple *pcVar3;
  c2_const_operand *src2;
  c2_const_operand *src1;
  uint16_t type;
  uint uVar4;
  uint64_t uVar5;
  c2_insert_fn *insert_fn;
  
  pcVar3 = val->sym->def;
  pcVar1 = pcVar3->src;
  if (pcVar1->op == 0x146) {
    uVar4 = (pcVar1->u18).lo;
    if (elem_size == 1) {
      uVar4 = uVar4 & 0xff | uVar4 << 8;
    }
    pcVar3->type = 0x1004;
    operand_retype(pcVar1,0x1004,0);
    operand_retype(pcVar3->dst,0x1004,0);
    operand_retype(val,0x1004,0);
    operand_retype(val,0x1004,0);
    pcVar1 = pcVar3->src;
    uVar5 = const_normalize(pcVar1->type,uVar4 << 0x10 | uVar4 & 0xffff,0);
    pcVar1->u18 = (c2_operand_u18)(int)uVar5;
    pcVar1->tag = (int)(uVar5 >> 0x20);
    pcVar1 = lower_value_into_register(t,val,reg);
    return pcVar1;
  }
  type = (elem_size != 1) + 0x1001;
  pcVar2 = lower_value_into_register(t,val,reg);
  op = operand_new_temp(type);
  pcVar3 = tuple_new_pseudo(0x19e,type);
  tuple_append_dst(pcVar3,op);
  op->sym->def = pcVar3;
  tuple_insert_before(t,pcVar3);
  insert_fn = tuple_insert_after;
  src2 = operand_new_intconst(0x1004,count,0);
  src1 = operand_new_intconst(0x1004,0x182,0);
  pcVar3 = tuple_new_binary_temp(0x166,type,src1,src2,insert_fn,pcVar3);
  pcVar1 = pcVar3->dst;
  pcVar2 = tuple_append_src(pcVar3,pcVar2);
  tuple_append_src(pcVar3,op);
  retie_register_chain(pcVar2,pcVar1);
  if (reg != (c2_symbol *)0x0) {
    pcVar1 = operand_narrow_to(pcVar1,reg->type,0);
    return pcVar1;
  }
  return pcVar1;
}

