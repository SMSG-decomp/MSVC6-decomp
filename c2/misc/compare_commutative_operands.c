int __fastcall compare_commutative_operands(c2_node *n,c2_node *n2)

{
  c2_node *pcVar1;
  c2_node *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  pcVar1 = factor_strip_ops(n);
  pcVar2 = factor_strip_ops(n2);
  if (pcVar2->kind != '\a') {
    return (pcVar1->kind != '\a') - 1;
  }
  if (pcVar1->kind == '\a') {
    uVar4 = pcVar1[1].rank_or_prev;
    uVar5 = *(uint *)&pcVar1[1].kind;
    if ((int)uVar4 < 0) {
      bVar7 = uVar5 != 0;
      uVar5 = -uVar5;
      uVar4 = -(uVar4 + bVar7);
    }
    uVar6 = *(uint *)&pcVar2[1].kind;
    uVar3 = pcVar2[1].rank_or_prev;
    if ((int)uVar3 < 0) {
      bVar7 = uVar6 != 0;
      uVar6 = -uVar6;
      uVar3 = -(uVar3 + bVar7);
    }
    if ((uVar3 <= uVar4) && ((uVar3 < uVar4 || (uVar6 < uVar5)))) {
      return -1;
    }
    if ((uVar5 == uVar6) && (uVar4 == uVar3)) {
      return 0;
    }
  }
  return 1;
}

