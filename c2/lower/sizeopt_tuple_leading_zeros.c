uint32_t __fastcall sizeopt_tuple_leading_zeros(c2_tuple *t)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  c2_operand *pcVar6;
  uint uVar7;
  uint uVar8;
  
  switch(t->op) {
  case 0x15f:
    pcVar6 = t->src;
    uVar2 = t->type;
    uVar3 = pcVar6->type;
    if ((uVar3 & 0xfff) < (uVar2 & 0xfff)) {
      uVar4 = operand_known_leading_zero_bits(pcVar6);
      if (((pcVar6->type & 0xf000) == 0x2000) || (0 < (int)uVar4)) {
        return uVar4 + ((uVar2 & 0xfff) - (uVar3 & 0xfff)) * 8;
      }
    }
  default:
    uVar4 = 0;
    break;
  case 0x172:
    pcVar6 = t->src;
    uVar4 = operand_known_leading_zero_bits(pcVar6->next);
    uVar5 = operand_known_leading_zero_bits(pcVar6);
    if ((int)uVar5 <= (int)uVar4) {
      pcVar6 = pcVar6->next;
    }
    bVar1 = pcVar6->kind;
    if (bVar1 != 0) {
      if (bVar1 < 3) {
        if (pcVar6->sym->def != (c2_tuple *)0x0) {
          return (uint)(pcVar6->sym->u30).globopt.live;
        }
      }
      else if (bVar1 == 7) {
        uVar7 = (pcVar6->u18).lo;
        uVar4 = 0;
        switch(pcVar6->type & 0xfff) {
        case 1:
          uVar8 = uVar7 & 0xff;
          if (uVar8 == 0) {
            return 8;
          }
          if ((uVar7 & 0x80) == 0) {
            do {
              uVar8 = uVar8 << 1;
              uVar4 = uVar4 + 1;
            } while ((uVar8 & 0x80) == 0);
            return uVar4;
          }
          break;
        case 2:
          uVar8 = uVar7 & 0xffff;
          if (uVar8 == 0) {
            return 0x10;
          }
          if ((uVar7 & 0x8000) == 0) {
            do {
              uVar8 = uVar8 << 1;
              uVar4 = uVar4 + 1;
            } while ((uVar8 & 0x8000) == 0);
            return uVar4;
          }
          break;
        case 4:
          if (uVar7 == 0) {
            return 0x20;
          }
          for (; (uVar7 & 0x80000000) == 0; uVar7 = uVar7 << 1) {
            uVar4 = uVar4 + 1;
          }
          break;
        case 0x10:
          return 0;
        }
        return uVar4;
      }
    }
    return 0;
  case 0x173:
    pcVar6 = t->src;
    uVar4 = operand_known_leading_zero_bits(pcVar6->next);
    uVar5 = operand_known_leading_zero_bits(pcVar6);
    if ((int)uVar4 <= (int)uVar5) {
      pcVar6 = pcVar6->next;
    }
    uVar4 = operand_known_leading_zero_bits(pcVar6);
    return uVar4;
  case 0x177:
    pcVar6 = t->src;
    uVar4 = operand_known_leading_zero_bits(pcVar6);
    pcVar6 = pcVar6->next;
    if ((pcVar6->kind == '\a') && ((0 < (int)uVar4 || ((t->type & 0xf000) == 0x2000)))) {
      return (int)&((pcVar6->u18).reg)->fe + uVar4;
    }
  }
  return uVar4;
}

