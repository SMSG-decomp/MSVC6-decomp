c2_operand * __fastcall operand_new_fconst(uint16_t type,c2_float_const *value)

{
  c2_operand *pcVar1;
  
  pcVar1 = (c2_operand *)node_alloc('\t');
  pcVar1->type = type;
  pcVar1->sym = (c2_symbol *)value;
  pcVar1->op = 0x148;
  return pcVar1;
}

