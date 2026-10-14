c2_operand * __fastcall operand_new_temp_in_reg(int regno,uint16_t type)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  
  sym = symbol_new_temp(type);
  pcVar1 = operand_new_reg(0x149,type,sym,g_reg_symbols + regno);
  return pcVar1;
}

