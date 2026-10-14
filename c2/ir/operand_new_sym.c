c2_operand * __fastcall operand_new_sym(uint32_t op,uint16_t type,c2_symbol *sym)

{
  c2_operand *pcVar1;
  
  pcVar1 = (c2_operand *)node_alloc('\x02');
  pcVar1->op = op;
  pcVar1->type = type;
  pcVar1->sym = sym;
  return pcVar1;
}

