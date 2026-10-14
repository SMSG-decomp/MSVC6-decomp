c2_operand * __fastcall operand_low_byte(c2_operand *op,int off,int fresh)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  
  if (op->kind == '\x01') {
    if ((fresh == 0) || (op->sym->def == (c2_tuple *)0x0)) {
      pcVar1 = op->sym;
    }
    else {
      pcVar1 = symbol_new_temp(0x1004);
    }
    pcVar1 = symbol_get_part(pcVar1,0x1001,1,off);
    pcVar2 = operand_new_reg(0x149,0x1001,pcVar1,(op->u18).reg);
    return pcVar2;
  }
  if (op->kind != '\x02') {
    pcVar2 = (c2_operand *)node_clone((c2_node *)op);
    pcVar2->type = 0x1001;
    pcVar2->disp = pcVar2->disp + off;
    return pcVar2;
  }
  pcVar1 = symbol_get_part(op->sym,0x1001,1,off);
  pcVar2 = operand_new_sym(op->op,0x1001,pcVar1);
  return pcVar2;
}

