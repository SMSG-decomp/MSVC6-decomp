int __fastcall late_cse_use_register(c2_tuple *t,c2_operand *op,c2_symbol *reg)

{
  ushort type;
  c2_register_descriptor *pcVar1;
  c2_operand *new_op;
  uint uVar2;
  uint uVar3;
  
  uVar2 = t->op;
  if ((uVar2 != 0) && (uVar2 < 0x144)) {
    switch(uVar2) {
    case 4:
    case 6:
    case 8:
    case 10:
    case 0xb:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0xa3:
    case 0xc1:
    case 0xca:
    case 0xcb:
      break;
    case 0x2d:
    case 0x32:
      if (t->dst->kind == '\x01') {
        pcVar1 = (t->dst->u18).reg;
        if (pcVar1 == g_reg_symbols + 6) {
          return 0;
        }
        if (pcVar1 == g_reg_symbols + 5) {
          return 0;
        }
      }
    default:
      type = op->type;
      uVar3 = type & 0xfff;
      uVar2 = reg->size >> 3;
      if (((int)uVar3 <= (int)uVar2) && (((type & 0xfff) != 1 || (reg->storage->id < 5)))) {
        if (uVar3 != uVar2) {
          reg = reg_find_subreg(reg,uVar3 << 3,0);
        }
        new_op = operand_new_reg(0x149,type,reg,reg);
        tuple_replace_src(t,op,new_op);
        return 1;
      }
    }
  }
  return 0;
}

