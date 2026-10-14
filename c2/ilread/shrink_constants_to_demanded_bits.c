void __thiscall shrink_constants_to_demanded_bits(c2_operand *n,uint32_t mask_lo,uint32_t mask_hi)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  c2_operand *pcVar4;
  uint32_t new_lo;
  uint uVar5;
  c2_operand *child;
  uint uVar6;
  uint uVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  int64_t iVar12;
  
  uVar2 = n->op - 0x146;
  if (0x31 < uVar2) {
switchD_1074a8f7_caseD_147:
    return;
  }
  uVar10 = CONCAT44(mask_hi,mask_lo);
  do {
    uVar6 = (uint)(uVar10 >> 0x20);
    uVar3 = (uint)uVar10;
    switch((&switchD_1074a8f7::switchdataD_1074ab60)[uVar2]) {
    case 0x146:
      uVar2 = (n->u18).lo;
      uVar5 = n->tag;
      new_lo = uVar2 & uVar3;
      uVar7 = uVar5 & uVar6;
      uVar8 = const_normalize(n->type,~(~uVar3 | uVar2),~(~uVar6 | uVar5));
      if (uVar8 < CONCAT44(uVar7,new_lo)) {
        uVar8 = const_normalize(n->type,~uVar3,~uVar6);
        new_lo = uVar2 | (uint)uVar8;
        uVar7 = uVar5 | (uint)(uVar8 >> 0x20);
      }
      if (((n->u18).lo == new_lo) && (n->tag == uVar7)) {
        return;
      }
      (n->u18).lo = new_lo;
      n->tag = uVar7;
      g_simplify_changed = 1;
      return;
    default:
      goto switchD_1074a8f7_caseD_147;
    case 0x16d:
    case 0x16e:
      iVar12 = shift_loop_noop(uVar3,uVar6);
      iVar12 = allshl((uint8_t)iVar12,0,2);
      child = (n->u18).children;
      uVar6 = (int)iVar12 - 1;
      uVar2 = (int)((ulonglong)iVar12 >> 0x20) - (uint)((int)iVar12 == 0);
      if (child == (c2_operand *)0x0) {
        return;
      }
      do {
        shrink_constants_to_demanded_bits(child,uVar6,uVar2);
        uVar1 = child->op;
        if ((uVar1 == 0x172) || (pcVar4 = child, uVar1 == 0x171)) {
          pcVar4 = (child->u18).children;
        }
        if (pcVar4->kind == '\a') {
          if (uVar1 == 0x171) {
            if (((int)pcVar4->tag < 1) && (((int)pcVar4->tag < 0 || ((pcVar4->u18).lo < 0x20)))) {
              uVar11 = allshl((uint8_t)(pcVar4->u18).lo,0,1);
            }
            else {
              uVar11 = 0;
            }
          }
          else {
            uVar11._0_4_ = pcVar4->u18;
            uVar11._4_4_ = pcVar4->tag;
          }
          uVar5 = (uint)(uVar11 | uVar10);
          uVar3 = (uint)((uVar11 | uVar10) >> 0x20);
          uVar10 = uVar10 | uVar11;
          uVar6 = uVar6 & -(-uVar5 & uVar5);
          uVar2 = uVar2 & -((-(uVar3 + (uVar5 != 0)) & uVar3) + (uint)((-uVar5 & uVar5) != 0));
        }
        child = child->next;
      } while (child != (c2_operand *)0x0);
      return;
    case 0x16f:
      iVar12 = shift_loop_noop(uVar3,uVar6);
      iVar12 = allshl((uint8_t)iVar12,0,2);
      uVar10 = CONCAT44((int)((ulonglong)iVar12 >> 0x20) - (uint)((int)iVar12 == 0),(int)iVar12 + -1
                       );
    case 0x172:
    case 0x173:
    case 0x174:
      child = (n->u18).children;
      if (child == (c2_operand *)0x0) {
        return;
      }
      do {
        shrink_constants_to_demanded_bits(child,(uint32_t)uVar10,(uint32_t)(uVar10 >> 0x20));
        child = child->next;
      } while (child != (c2_operand *)0x0);
      return;
    case 0x171:
      child = (n->u18).children;
      if (child->next->kind != '\a') {
        return;
      }
      uVar8 = shift_mask_constant((c2_tuple *)n);
      uVar9 = aullshr((uint8_t)(child->next->u18).lo,uVar6,uVar3);
      uVar10 = uVar8 & uVar9;
      break;
    case 0x177:
      child = ((n->u18).children)->next;
      if (child->kind != '\a') {
        return;
      }
      if (((int)child->tag < 1) && (((int)child->tag < 0 || ((child->u18).lo < 0x20)))) {
        uVar10 = allshl((uint8_t)(child->u18).lo,uVar6,uVar3);
      }
      else {
        uVar10 = 0;
      }
      if ((n->type & 0xf000) == 0x1000) {
        uVar11 = sign_extend_to_size(n,0x80000000);
        uVar10 = uVar11 | uVar10;
      }
      uVar10 = const_normalize(n->type,(uint32_t)uVar10,(int32_t)(uVar10 >> 0x20));
    case 0x160:
      child = (n->u18).children;
    }
    uVar2 = child->op - 0x146;
    n = child;
    if (0x31 < uVar2) {
      return;
    }
  } while( true );
}

