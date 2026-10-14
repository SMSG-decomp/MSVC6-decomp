c2_operand * __fastcall operand_retype(c2_operand *op,uint16_t type,int offset)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  uint64_t uVar3;
  
  if (op->type != type) {
    uVar1 = op->kind;
    switch(uVar1) {
    default:
      pcVar2 = symbol_get_part(op->sym,type,type & 0xfff,offset);
      op->sym = pcVar2;
      if ((uVar1 == '\x01') && (((op->u18).reg)->cls == '\x01')) {
        pcVar2 = reg_find_subreg((op->u18).reg,(type & 0xfff) * 8,offset * 8);
        (op->u18).reg = pcVar2;
        op->type = type;
        return op;
      }
      break;
    case '\x05':
    case '\x06':
      op->disp = op->disp + offset;
      break;
    case '\a':
      uVar3 = const_normalize(type,(op->u18).lo,op->tag);
      op->u18 = (c2_operand_u18)(int)uVar3;
      op->tag = (int)(uVar3 >> 0x20);
      op->type = type;
      return op;
    }
    op->type = type;
  }
  return op;
}

