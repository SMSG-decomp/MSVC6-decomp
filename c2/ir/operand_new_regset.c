c2_operand * __fastcall operand_new_regset(c2_bitset *set)

{
  c2_operand *pcVar1;
  
  pcVar1 = (c2_operand *)node_alloc('\n');
  pcVar1->sym = (c2_symbol *)set;
  pcVar1->op = 0x158;
  return pcVar1;
}

