c2_operand * __fastcall operand_narrow_to(c2_operand *op,uint16_t type,int off)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  
  if ((op->type != type) || (op->sym->offset != off)) {
    if ((op->flags & 0x10) != 0) {
      op = (c2_operand *)node_clone((c2_node *)op);
    }
    uVar1 = op->kind;
    switch(uVar1) {
    case '\0':
      halt_baddata();
    case '\x01':
    case '\x02':
      pcVar2 = symbol_get_part(op->sym,type,type & 0xfff,off);
      op->sym = pcVar2;
      if ((uVar1 == '\x01') && (((op->u18).reg)->cls == '\x01')) {
        pcVar2 = reg_find_subreg((op->u18).reg,(type & 0xfff) * 8,off * 8);
        (op->u18).reg = pcVar2;
        op->type = type;
        return op;
      }
      break;
    case '\x05':
    case '\x06':
      op->disp = op->disp + off;
    }
    op->type = type;
  }
  return op;
}

