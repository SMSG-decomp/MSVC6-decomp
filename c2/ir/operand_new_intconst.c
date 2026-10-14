c2_const_operand * operand_new_intconst(uint16_t type,uint32_t lo,int32_t hi)

{
  c2_const_operand *pcVar1;
  uint64_t uVar2;
  
  pcVar1 = (c2_const_operand *)node_alloc('\a');
  pcVar1->op = 0x146;
  pcVar1->type = type;
  uVar2 = const_normalize(type,lo,hi);
  pcVar1->u18 = (c2_operand_u18)(int)uVar2;
  pcVar1->tag = (int)(uVar2 >> 0x20);
  return pcVar1;
}

