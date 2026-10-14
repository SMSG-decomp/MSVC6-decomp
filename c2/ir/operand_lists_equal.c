int __fastcall operand_lists_equal(c2_operand *a,c2_operand *b)

{
  uint8_t uVar1;
  int iVar2;
  
  if (a == (c2_operand *)0x0) {
    return (uint)(b == (c2_operand *)0x0);
  }
  if ((b != (c2_operand *)0x0) && (uVar1 = a->kind, uVar1 == b->kind)) {
    iVar2 = types_compatible(a->type,b->type);
    if (iVar2 != 0) {
      switch(uVar1) {
      case '\0':
        return 0;
      case '\x01':
        if ((a->u18).reg == (b->u18).reg) {
          return 1;
        }
        break;
      default:
        if (a->sym == b->sym) {
          return 1;
        }
        break;
      case '\x04':
        if (a->sym == b->sym) {
          return 1;
        }
        break;
      case '\x05':
      case '\x06':
        if ((((a->base_sym == b->base_sym) && (a->disp == b->disp)) &&
            (((a->flags11 ^ b->flags11) & 7) == 0)) && (((a->flags ^ b->flags) & 0xf) == 0)) {
          iVar2 = operand_lists_equal(a->base,b->base);
          if (iVar2 != 0) {
            iVar2 = operand_lists_equal(a->index,b->index);
            if (iVar2 != 0) {
              return 1;
            }
          }
        }
        break;
      case '\a':
        if (((a->u18).reg == (b->u18).reg) && (a->tag == b->tag)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

