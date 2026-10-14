uint32_t __fastcall pack_expression_cost(c2_operand *n)

{
  byte bVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  c2_operand *child;
  
  bVar1 = n->kind;
  if ((1 << (bVar1 & 0x1f) & 0xffeU) == 0) {
    uVar5 = ((n->u18).children)->rank;
    uVar6 = uVar5 >> 0x18;
    uVar5 = (uVar5 >> 0x10 & 0xff) + 1;
    child = ((n->u18).children)->next;
    while (child != (c2_operand *)0x0) {
      pcVar2 = child->next;
      uVar4 = child->rank >> 0x18;
      uVar5 = uVar5 + (child->rank >> 0x10 & 0xff);
      child = pcVar2;
      if (uVar6 < uVar4) {
        uVar6 = uVar4 + 1;
      }
      else if (uVar4 == uVar6) {
        uVar6 = uVar6 + 1;
      }
    }
    if (bVar1 == 0xe) {
      uVar6 = uVar6 + 7;
    }
    else if (bVar1 == 0x12) {
      uVar6 = uVar6 + 5;
    }
    uVar3 = hash_operand(n);
    return uVar3 & 0xffff | (uVar5 & 0xff | uVar6 << 8) << 0x10;
  }
  uVar3 = hash_operand(n);
  return uVar3 & 0xffff | (uint)((1 << (n->kind & 0x1f) & 0x380U) == 0) << 0x10;
}

