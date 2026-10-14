c2_operand * __fastcall operand_new_temp(uint16_t type)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  
  sym = symbol_new_temp(type);
  pcVar1 = operand_new_reg(0x149,type,sym,sym);
  return pcVar1;
}

