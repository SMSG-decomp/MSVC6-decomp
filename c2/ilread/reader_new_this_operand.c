c2_operand * reader_new_this_operand(void)

{
  uint uVar1;
  c2_operand *pcVar2;
  c2_operand *index;
  uint32_t alias_tag;
  
  uVar1 = g_cur_func_sym->attrs & 0x1c;
  if (((uVar1 != 4) && (uVar1 != 0x14)) && (uVar1 != 0x18)) {
    alias_tag = 0;
    index = (c2_operand *)0x0;
    pcVar2 = operand_new_hardreg(5,0x1004);
    pcVar2 = operand_new_mem(0x14c,0x1004,(c2_symbol *)0x0,4,pcVar2,index,alias_tag);
    return pcVar2;
  }
  pcVar2 = operand_new_reg(0x149,0x1004,g_reg_symbols + 2,g_reg_symbols + 2);
  return pcVar2;
}

