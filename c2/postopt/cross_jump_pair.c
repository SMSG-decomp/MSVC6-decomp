int __fastcall cross_jump_pair(c2_tuple *j1,c2_tuple *j2,uint32_t mark,int *swapped)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  c2_tuple *pcVar6;
  ushort uVar7;
  int iVar8;
  c2_tuple *to_end;
  c2_tuple *pcVar9;
  c2_tuple *from_before;
  int local_14;
  c2_tuple *local_8;
  c2_tuple *local_4;
  
  if ((((j1->op != 0) && (j1->op < 0x144)) && (j2->op != 0)) && (j2->op < 0x144)) {
    bVar2 = false;
    local_4 = (c2_tuple *)0x0;
    local_8 = (c2_tuple *)0x0;
    bVar4 = false;
    bVar3 = false;
    local_14 = 0;
    from_before = j1;
    pcVar6 = j2;
    while( true ) {
      from_before = from_before->prev;
      pcVar6 = pcVar6->prev;
      if (((!bVar2) &&
          (((from_before->kind == '\x0e' ||
            ((from_before->kind == '\x11' &&
             (((from_before->u20).cond_cells != (c2_cond_cell *)0x0 || (from_before->op == 0x18b))))
            )) && (bVar2 = true, bVar3)))) && (bVar4)) {
        cross_jump_fix_labels(from_before,j1,pcVar6,j2,mark,0);
        bVar3 = false;
      }
      for (; (from_before->kind == '\x1a' || (from_before->op == 0x1bc));
          from_before = from_before->prev) {
        bVar3 = true;
      }
      for (; (pcVar6->kind == '\x1a' || (pcVar6->op == 0x1bc)); pcVar6 = pcVar6->prev) {
        bVar4 = true;
      }
      if ((from_before == j2) || (pcVar6 == j1)) break;
      if (((from_before->kind == '\x11') &&
          (((from_before->u20).cond_cells == (c2_cond_cell *)0x0 && (from_before->op != 0x18b)))) ||
         (from_before->kind == '\x13')) {
        local_8 = from_before;
        local_4 = pcVar6;
      }
      iVar5 = tuples_equal(from_before,pcVar6);
      if (iVar5 == 0) break;
      local_14 = local_14 + 1;
    }
    *swapped = 0;
    if (local_14 != 0) {
      to_end = j2;
      pcVar9 = from_before;
      if (((g_opt_favor_speed != 0) &&
          (((from_before->kind != '\x11' || ((from_before->u20).cond_cells != (c2_cond_cell *)0x0))
           || (from_before->op == 0x18b)))) && (from_before->kind != '\x0f')) {
        if ((((pcVar6->kind == '\x11') && ((pcVar6->u20).cond_cells == (c2_cond_cell *)0x0)) &&
            (pcVar6->op != 0x18b)) || (pcVar6->kind == '\x0f')) {
          *swapped = 1;
          to_end = j1;
          j1 = j2;
          pcVar9 = pcVar6;
          pcVar6 = from_before;
          bVar3 = bVar4;
        }
        else {
          pcVar9 = from_before->next;
          iVar8 = 0;
          iVar5 = g_opt_favor_speed;
          do {
            if ((pcVar9->flags & 1) != 0) {
              iVar5 = tuple_encoded_length(pcVar9);
              iVar8 = iVar8 + iVar5;
              iVar5 = g_opt_favor_speed;
            }
          } while ((pcVar9 != j1) &&
                  (pcVar9 = pcVar9->next, iVar8 < (int)((-(uint)(iVar5 != 0) & 0x12) + 2)
                       ));
          uVar7._0_1_ = j1->flags12;
          uVar7._1_1_ = j1->flags13;
          uVar1._0_1_ = j2->flags12;
          uVar1._1_1_ = j2->flags13;
          if (uVar7 <= uVar1) {
            uVar7 = uVar1;
          }
          iVar5 = (-(uint)(iVar5 != 0) & 0x12) + 2;
          if (((int)(iVar8 + (uint)uVar7) <= iVar5) &&
             (from_before = local_8, pcVar6 = local_4, local_8 == (c2_tuple *)0x0)) {
            return 0;
          }
          iVar8 = iVar8 + (uint)uVar7 + (uint)uVar1;
          if (iVar5 < iVar8) {
            iVar5 = iVar8;
          }
          j2->flags12 = (char)(short)iVar5;
          j2->flags13 = (char)((ushort)(short)iVar5 >> 8);
          pcVar9 = from_before;
        }
      }
      if (bVar3) {
        cross_jump_fix_labels(pcVar9,j1,pcVar6,to_end,mark,1);
      }
      pcVar6 = label_after_or_create(pcVar6);
      tuple_retarget(j1,(c2_node *)pcVar6,0);
      tuple_range_free(pcVar9->next,j1);
      return 1;
    }
  }
  return 0;
}

