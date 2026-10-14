c2_operand * __fastcall operand_new_temp_sym(uint16_t type)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  
  sym = symbol_new_temp_plain(type);
  pcVar1 = operand_new_sym(0x14a,type,sym);
  return pcVar1;
}

