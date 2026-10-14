c2_operand * __fastcall find_dst_reg_operand(c2_symbol *reg,c2_tuple *t)

{
  c2_operand *pcVar1;
  
  for (pcVar1 = t->dst;
      (pcVar1 != (c2_operand *)0x0 && ((pcVar1->kind != '\x01' || ((pcVar1->u18).reg != reg))));
      pcVar1 = pcVar1->next) {
  }
  return pcVar1;
}

