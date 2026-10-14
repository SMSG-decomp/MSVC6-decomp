c2_operand * __fastcall operand_new_memeffect(uint32_t alias)

{
  c2_operand *pcVar1;
  
  pcVar1 = (c2_operand *)node_alloc('\v');
  pcVar1->sym = (c2_symbol *)alias;
  pcVar1->op = 0x159;
  pcVar1->type = 0x6000;
  return pcVar1;
}

