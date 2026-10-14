c2_operand * __fastcall
split_int64_operand_half(c2_tuple *anchor,c2_operand *op,c2_operand *opnd,c2_operand *cond)

{
  byte bVar1;
  uint32_t lo;
  c2_symbol *pcVar2;
  c2_const_operand *pcVar3;
  c2_operand *new_op;
  c2_operand *pcVar4;
  c2_operand *base;
  ushort type;
  uint64_t uVar5;
  
  if (op == (c2_operand *)0x0) {
    return (c2_operand *)0x0;
  }
  type = op->type & 0xf004 | 4;
  switch(op->kind) {
  case '\x01':
    pcVar2 = op->sym;
    if (((pcVar2->cls != '\x03') || (pcVar2->def == (c2_tuple *)0x0)) || (anchor->op != 0x17d)) {
      pcVar2 = symbol_get_part(pcVar2,type,0,0);
      op->sym = pcVar2;
      if (((op->u18).reg)->cls != '\x01') {
        set_operand_home(op,pcVar2);
      }
      op->type = type;
      pcVar2 = symbol_get_part(op->sym,type,0,4);
      pcVar4 = operand_new_reg(op->op,type,pcVar2,pcVar2);
      if (op->kind != '\x01') {
        return pcVar4;
      }
      if (((op->u18).reg)->cls != '\x01') {
        return pcVar4;
      }
      (pcVar4->u18).reg = g_reg_symbols + 3;
      return pcVar4;
    }
    op = copy_operand_to_temp_before(op,anchor);
  case '\x02':
    pcVar2 = symbol_get_part(op->sym,type,0,0);
    op->sym = pcVar2;
    op->type = type;
    pcVar2 = symbol_get_part(pcVar2,type,0,4);
    pcVar4 = operand_new_sym(op->op,type,pcVar2);
    pcVar4->flags11 = (op->flags11 ^ pcVar4->flags11) & 8 ^ pcVar4->flags11;
    break;
  case '\x06':
    pcVar4 = op->base;
    op->type = type;
    if ((((pcVar4 == (c2_operand *)0x0) || (pcVar4->kind != '\x01')) ||
        (pcVar2 = pcVar4->sym, pcVar2->cls != '\x03')) || (pcVar2->def == (c2_tuple *)0x0)) {
      pcVar4 = (c2_operand *)node_clone((c2_node *)op);
      pcVar4->disp = pcVar4->disp + 4;
    }
    else {
      if (anchor->op == 0x17d) {
        if (cond == (c2_operand *)0x0) {
          pcVar4 = copy_operand_to_temp_before(pcVar4,anchor);
        }
        pcVar4 = operand_new_mem(op->op,type,op->base_sym,op->disp,pcVar4,(c2_operand *)0x0,op->tag)
        ;
        bVar1 = op->flags;
        pcVar4->disp = pcVar4->disp + 4;
        pcVar4->flags = (bVar1 ^ pcVar4->flags) & 0x40 ^ pcVar4->flags;
        return pcVar4;
      }
      new_op = bind_value_to_new_temp(anchor,pcVar2,(uint)(opnd == (c2_operand *)0x0));
      base = new_op;
      if (opnd != (c2_operand *)0x0) {
        opnd->next = new_op;
        base = (c2_operand *)node_clone((c2_node *)pcVar4);
        tuple_replace_src(anchor,pcVar4,new_op);
      }
      pcVar4 = operand_new_mem(0x14c,type,op->base_sym,op->disp + 4,base,(c2_operand *)0x0,op->tag);
    }
    break;
  case '\a':
    lo = op->tag;
    op->type = type;
    pcVar3 = operand_new_intconst(type,lo,(int)lo >> 0x1f);
    uVar5 = const_normalize(type,(op->u18).lo,lo);
    op->u18 = (c2_operand_u18)(int)uVar5;
    op->tag = (int)(uVar5 >> 0x20);
    return pcVar3;
  }
  pcVar4->flags = (op->flags ^ pcVar4->flags) & 0x40 ^ pcVar4->flags;
  return pcVar4;
}

