c2_operand * __fastcall operand_new_cse_sym(uint32_t op,uint16_t type,c2_operand *a,c2_operand *b)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  
  sym = cse_find_or_make(op,type,a,b);
  pcVar1 = operand_new_sym(0x14a,type,sym);
  return pcVar1;
}

