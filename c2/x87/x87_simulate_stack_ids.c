int __fastcall x87_simulate_stack_ids(c2_tuple *t,c2_tuple *t2)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  uint uVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  bool bVar6;
  bool bVar7;
  uint32_t uVar8;
  int iVar9;
  int32_t iVar10;
  int iVar11;
  
  pcVar1 = t2->next;
  bVar6 = false;
  bVar7 = false;
  iVar10 = g_x87_tos;
  if (t != pcVar1) {
    do {
      pcVar2 = t->next;
      if (((t->flags & 1) != 0) &&
         ((((t->type & 0xf000) == 0x4000 || (t->kind == '\x0e')) || (t->op == 0x5b)))) {
        uVar3 = t->op;
        if (uVar3 < 0x163) {
          if (uVar3 != 0x162) {
            if (uVar3 == 0x5f) {
              uVar8 = g_x87_stack_ids[iVar10];
              iVar11 = ((t->src->u18).reg)->id - 0x1f;
              if (7 < iVar11) {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x1a3);
              }
              iVar11 = iVar10 - iVar11;
              g_x87_stack_ids[iVar10] = g_x87_stack_ids[iVar11];
              g_x87_stack_ids[iVar11] = uVar8;
              if ((bVar6) || (bVar7)) {
                bVar6 = true;
                bVar7 = true;
              }
              else {
                bVar7 = true;
              }
            }
            else if (uVar3 != 0x8e) goto LAB_1075c836;
          }
        }
        else {
          if (uVar3 == 0x166) {
            return -1;
          }
LAB_1075c836:
          pcVar5 = t->dst;
          bVar7 = false;
          for (pcVar4 = t->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
            if ((pcVar4->kind == '\x01') && ((pcVar4->type & 0xf000) == 0x4000)) {
              pcVar4->rank = g_x87_stack_ids[iVar10 - (((pcVar4->u18).reg)->id - 0x1f)];
            }
          }
          if ((pcVar5->kind == '\x01') && ((pcVar5->type & 0xf000) == 0x4000)) {
            iVar11 = ((pcVar5->u18).reg)->id - 0x1f;
          }
          else {
            iVar11 = 0;
          }
          iVar9 = x87_stack_effect(t);
          iVar10 = g_x87_tos;
          switch(iVar9) {
          case 0:
            uVar8 = g_x87_next_value_id + 1;
            iVar11 = g_x87_tos - iVar11;
            g_x87_next_value_id = uVar8;
            pcVar5->rank = uVar8;
            g_x87_stack_ids[iVar11] = uVar8;
            break;
          case 1:
            if (0xf < g_x87_tos) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x415);
            }
            uVar8 = g_x87_next_value_id + 1;
            iVar10 = g_x87_tos + 1;
            g_x87_tos = iVar10;
            g_x87_next_value_id = uVar8;
            g_x87_stack_ids[iVar10] = uVar8;
            pcVar5->rank = uVar8;
            break;
          case -2:
            uVar8 = g_x87_next_value_id + 1;
            iVar10 = g_x87_tos + -2;
            g_x87_next_value_id = uVar8;
            pcVar5->rank = uVar8;
            g_x87_stack_ids[g_x87_tos - iVar11] = uVar8;
            g_x87_tos = iVar10;
            break;
          case -1:
            uVar8 = g_x87_next_value_id + 1;
            iVar10 = g_x87_tos + -1;
            g_x87_next_value_id = uVar8;
            pcVar5->rank = uVar8;
            g_x87_stack_ids[g_x87_tos - iVar11] = uVar8;
            g_x87_tos = iVar10;
          }
        }
      }
      t = pcVar2;
    } while (pcVar2 != pcVar1);
    if (bVar6) {
      return 1;
    }
  }
  return -2;
}

