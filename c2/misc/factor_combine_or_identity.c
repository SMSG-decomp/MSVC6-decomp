void __fastcall factor_combine_or_identity(c2_tuple *t,c2_node *a,int op)

{
  c2_operand *dlo;
  c2_operand *dhi;
  c2_node *pcVar1;
  c2_operand *lo;
  int32_t hi;
  c2_operand *hi_00;
  uint32_t lo_00;
  bool bVar2;
  uint64_t uVar3;
  longlong lVar4;
  int64_t iVar5;
  
  pcVar1 = factor_strip_ops(a);
  if (pcVar1->kind != '\a') {
LAB_1074bb01:
    identity_constant_for_op(op,pcVar1->type);
    return;
  }
  lo = *(c2_operand **)&pcVar1[1].kind;
  dlo = t->src;
  hi_00 = (c2_operand *)pcVar1[1].rank_or_prev;
  dhi = t->dst;
  if (((lo == dlo) && (hi_00 == dhi)) && ((a->kind != '\a' || ((op != 0x171 && (op != 0x177))))))
  goto LAB_1074bb01;
  switch(op) {
  case 0x16f:
    uVar3 = lldiv_helper((uint32_t)lo,(uint32_t)hi_00,(uint32_t)dlo,(uint32_t)dhi);
    operand_new_intconst(pcVar1->type,(uint32_t)uVar3,(int32_t)(uVar3 >> 0x20));
    return;
  case 0x171:
    if (a->kind == '\a') {
      lVar4 = allshr((uint32_t)lo,(int32_t)hi_00,(uint8_t)dlo);
      operand_new_intconst(pcVar1->type,(uint32_t)lVar4,(int32_t)((ulonglong)lVar4 >> 0x20));
      return;
    }
    lo_00 = (int)lo - (int)dlo;
    hi = ((int)hi_00 - (int)dhi) - (uint)(lo < dlo);
    if (-1 < hi) {
      if (hi == 0 ||
          SBORROW4((int)hi_00,(int)dhi) != SBORROW4((int)hi_00 - (int)dhi,(uint)(lo < dlo))) {
        operand_new_intconst(pcVar1->type,lo_00,hi);
        return;
      }
LAB_10793152:
      operand_new_intconst(pcVar1->type,lo_00,hi);
      return;
    }
    break;
  case 0x172:
    goto override_jmp_1074bb29_case_2;
  case 0x173:
    operand_new_intconst(pcVar1->type,(uint)dlo ^ (uint)lo,(uint)dhi ^ (uint)hi_00);
    return;
  case 0x177:
    if (a->kind == '\a') {
      iVar5 = allshl((uint8_t)dlo,(int32_t)hi_00,(uint32_t)lo);
      operand_new_intconst(pcVar1->type,(uint32_t)iVar5,(int32_t)((ulonglong)iVar5 >> 0x20));
      return;
    }
    lo_00 = (int)lo - (int)dlo;
    hi = (int)hi_00 + (-(uint)(lo < dlo) - (int)dhi);
    if (-1 < hi) goto LAB_10793152;
  }
  bVar2 = dlo < lo;
  lo = (c2_operand *)((int)dlo - (int)lo);
  hi_00 = (c2_operand *)((int)dhi + (-(uint)bVar2 - (int)hi_00));
override_jmp_1074bb29_case_2:
  operand_new_intconst(pcVar1->type,(uint32_t)lo,(int32_t)hi_00);
  return;
}

