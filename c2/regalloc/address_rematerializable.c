int __fastcall address_rematerializable(c2_operand *addr,c2_operand *base,int uses)

{
  if (addr->base == base) {
    if ((addr->flags & 0xf) == 0) {
      if (addr->index == (c2_operand *)0x0) {
        return 1;
      }
      if (uses < 2) {
        return 1;
      }
      return 0;
    }
  }
  else if ((addr->flags & 0xf) == 0) {
    if (uses < 2) {
      return 1;
    }
    if ((addr->base == (c2_operand *)0x0) && (addr->op != 0x14e)) {
      return 1;
    }
  }
  return 0;
}

