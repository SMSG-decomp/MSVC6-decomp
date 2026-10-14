c2_operand * __fastcall operand_new_hardreg(int regno,uint16_t type)

{
  c2_operand *pcVar1;
  
  pcVar1 = operand_new_reg(0x149,type,g_reg_symbols + regno,g_reg_symbols + regno);
  return pcVar1;
}

