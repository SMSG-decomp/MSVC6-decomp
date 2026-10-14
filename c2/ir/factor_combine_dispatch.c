void __fastcall factor_combine_dispatch(c2_node *a,c2_node *b,int op)

{
  uint uVar1;
  uint uVar2;
  c2_node *pcVar3;
  c2_node *pcVar4;
  uint32_t uVar5;
  int iVar6;
  bool bVar7;
  
  pcVar3 = factor_strip_ops(a);
  pcVar4 = factor_strip_ops(b);
  if (pcVar3->kind == '\a') {
    switch(op) {
    case 0x16f:
      pcVar4 = node_clone(pcVar4);
      uVar5 = pcVar4[1].rank_or_prev;
      iVar6 = *(int *)&pcVar4[1].kind;
      if ((int)uVar5 < 0) {
        bVar7 = iVar6 != 0;
        iVar6 = -iVar6;
        uVar5 = -(uVar5 + bVar7);
      }
      pcVar4[1].kind = (char)iVar6;
      pcVar4[1].flags = (char)((uint)iVar6 >> 8);
      pcVar4[1].type = (short)((uint)iVar6 >> 0x10);
      pcVar4[1].rank_or_prev = uVar5;
      return;
    case 0x171:
      if (a->kind == '\a') goto override_jmp_1074b9df_case_3;
      if (b->kind != '\a') {
        if (((int)pcVar4[1].rank_or_prev <= (int)pcVar3[1].rank_or_prev) &&
           (((int)pcVar4[1].rank_or_prev < (int)pcVar3[1].rank_or_prev ||
            (uVar1._0_1_ = pcVar4[1].kind, uVar1._1_1_ = pcVar4[1].flags,
            uVar1._2_2_ = pcVar4[1].type, uVar2._0_1_ = pcVar3[1].kind,
            uVar2._1_1_ = pcVar3[1].flags, uVar2._2_2_ = pcVar3[1].type, uVar1 <= uVar2))))
        goto override_jmp_1074b9df_case_3;
      }
      break;
    case 0x173:
      goto override_jmp_1074b9df_case_3;
    }
  }
  pcVar4 = pcVar3;
override_jmp_1074b9df_case_3:
  node_clone(pcVar4);
  return;
}

