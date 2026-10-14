uint32_t __fastcall operand_known_leading_zero_bits(c2_operand *op)

{
  byte bVar1;
  uint32_t uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = op->kind;
  if (bVar1 != 0) {
    if (bVar1 < 3) {
      if (op->sym->def != (c2_tuple *)0x0) {
        return (uint)(op->sym->u30).globopt.live;
      }
    }
    else if (bVar1 == 7) {
      uVar3 = (op->u18).lo;
      uVar2 = 0;
      switch(op->type & 0xfff) {
      case 1:
        uVar4 = uVar3 & 0xff;
        if (uVar4 == 0) {
          return 8;
        }
        if ((uVar3 & 0x80) == 0) {
          do {
            uVar4 = uVar4 << 1;
            uVar2 = uVar2 + 1;
          } while ((uVar4 & 0x80) == 0);
          return uVar2;
        }
        break;
      case 2:
        uVar4 = uVar3 & 0xffff;
        if (uVar4 == 0) {
          return 0x10;
        }
        if ((uVar3 & 0x8000) == 0) {
          do {
            uVar4 = uVar4 << 1;
            uVar2 = uVar2 + 1;
          } while ((uVar4 & 0x8000) == 0);
          return uVar2;
        }
        break;
      case 4:
        if (uVar3 == 0) {
          return 0x20;
        }
        for (; (uVar3 & 0x80000000) == 0; uVar3 = uVar3 << 1) {
          uVar2 = uVar2 + 1;
        }
        break;
      case 0x10:
        return 0;
      }
      return uVar2;
    }
  }
  return 0;
}

