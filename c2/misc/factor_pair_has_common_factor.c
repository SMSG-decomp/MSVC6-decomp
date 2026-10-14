int __fastcall factor_pair_has_common_factor(c2_tuple *t,c2_operand *n,c2_operand *n2,int inner_op)

{
  uint16_t type;
  uint32_t hi;
  uint32_t lo;
  c2_fe_symbol *pcVar1;
  char *pcVar2;
  uint lo_00;
  uint hi_00;
  uint dlo;
  uint dhi;
  c2_node *pcVar3;
  uint8_t count;
  c2_operand *pcVar4;
  uint32_t uVar5;
  bool bVar6;
  int64_t iVar7;
  uint64_t uVar8;
  longlong lVar9;
  
  if ((inner_op == 0x171) || (inner_op == 0x177)) {
    pcVar4 = n;
    if ((n2->kind == '\a') && (pcVar4 = n2, n2 = n, n->kind == '\a')) {
      return 0;
    }
    n = pcVar4;
    if (pcVar4->kind != '\a') goto LAB_1074b829;
    hi = pcVar4->tag;
    lo = (pcVar4->u18).lo;
    pcVar1 = ((n2->u18).reg)->fe;
    pcVar2 = pcVar1->name;
    uVar5 = pcVar1->coff_symbol;
    count = (uint8_t)pcVar2;
    if (inner_op == 0x171) {
      if (t->op == 0x172) {
        return 1;
      }
      if (((int)uVar5 < 1) && (((int)uVar5 < 0 || (pcVar2 < (char *)0x20)))) {
        lVar9 = allshr(lo,hi,count);
        iVar7 = allshl(count,(int32_t)((ulonglong)lVar9 >> 0x20),(uint32_t)lVar9);
      }
      else {
        iVar7 = 0;
      }
      if ((uint32_t)iVar7 != lo) {
        return 0;
      }
      bVar6 = (uint32_t)((ulonglong)iVar7 >> 0x20) == hi;
    }
    else {
      if (((int)uVar5 < 1) && (((int)uVar5 < 0 || (pcVar2 < (char *)0x20)))) {
        iVar7 = allshl(count,hi,lo);
      }
      else {
        iVar7 = 0;
      }
      type = n2->type;
      uVar8 = const_normalize(type,(uint32_t)iVar7,(int32_t)((ulonglong)iVar7 >> 0x20));
      uVar5 = (uint32_t)(uVar8 >> 0x20);
      if ((type & 0xf000) == 0x1000) {
        lVar9 = allshr((uint32_t)uVar8,uVar5,count);
        if ((uint32_t)lVar9 != lo) {
          return 0;
        }
        bVar6 = (uint32_t)((ulonglong)lVar9 >> 0x20) == hi;
      }
      else {
        if (t->op == 0x172) {
          return 1;
        }
        uVar8 = aullshr(count,uVar5,(uint32_t)uVar8);
        if ((uint32_t)uVar8 != lo) {
          return 0;
        }
        bVar6 = (uint32_t)(uVar8 >> 0x20) == hi;
      }
    }
LAB_1074b810:
    if (bVar6) {
      return 1;
    }
  }
  else {
LAB_1074b829:
    pcVar3 = factor_strip_ops((c2_node *)n);
    lo_00._0_1_ = pcVar3[1].kind;
    lo_00._1_1_ = pcVar3[1].flags;
    lo_00._2_2_ = pcVar3[1].type;
    hi_00 = pcVar3[1].rank_or_prev;
    pcVar3 = factor_strip_ops((c2_node *)n2);
    dlo._0_1_ = pcVar3[1].kind;
    dlo._1_1_ = pcVar3[1].flags;
    dlo._2_2_ = pcVar3[1].type;
    dhi = pcVar3[1].rank_or_prev;
    switch(inner_op) {
    case 0x16f:
      if (n2->kind == '\a') {
        return 0;
      }
      if (dlo == 0 && dhi == 0) {
        return 0;
      }
      if ((dlo == 1) && (dhi == 0)) {
        return 0;
      }
      uVar8 = llrem_helper(lo_00,hi_00,dlo,dhi);
      bVar6 = uVar8 == 0;
      goto LAB_1074b810;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\factor.c",0x1ec);
    case 0x171:
    case 0x177:
      goto switchD_1074b856_caseD_171;
    case 0x172:
      if ((dlo & lo_00) != dlo) {
        return 0;
      }
      bVar6 = (dhi & hi_00) == dhi;
      break;
    case 0x173:
      if ((dlo | lo_00) != lo_00) {
        return 0;
      }
      bVar6 = (dhi | hi_00) == hi_00;
    }
    if (bVar6) {
switchD_1074b856_caseD_171:
      return 1;
    }
  }
  return 0;
}

