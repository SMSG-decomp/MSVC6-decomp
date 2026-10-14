c2_operand * __fastcall operand_new_reg(uint32_t op,uint16_t type,c2_symbol *sym,c2_symbol *storage)

{
  c2_operand *pcVar1;
  
  pcVar1 = (c2_operand *)node_alloc('\x01');
  pcVar1->op = op;
  pcVar1->type = type;
  pcVar1->sym = sym;
  (pcVar1->u18).reg = storage;
  return pcVar1;
}

