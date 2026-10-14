c2_operand * __fastcall operand_at_offset_2(c2_operand *base,uint16_t type,int off,int tag)

{
  c2_operand *pcVar1;
  c2_symbol *sym;
  
  if ((1 << (base->kind & 0x1f) & 6U) != 0) {
    pcVar1 = operand_new_mem(0x14c,type,(c2_symbol *)0x0,off,base,(c2_operand *)0x0,tag);
    return pcVar1;
  }
  sym = symbol_get_part(base->sym,type,0,off);
  pcVar1 = operand_new_sym(base->op,type,sym);
  return pcVar1;
}

