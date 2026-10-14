c2_operand * __fastcall distribute_and_propagate(c2_operand *node,c2_tuple *parent)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_fe_symbol *pcVar3;
  c2_fe_symbol *opnd;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  uint32_t uVar6;
  bool bVar7;
  c2_operand *local_4;
  
  local_4 = node;
  switch(node->kind) {
  case '\x01':
  case '\x02':
    if ((((1 << (node->kind & 0x1f) & 6U) != 0) &&
        (pcVar1 = node->sym->def, pcVar1 != (c2_tuple *)0x0)) && (pcVar1->op == 0x15b)) {
      local_4 = propagate_copy_into_use(node,parent);
    }
    break;
  case '\x05':
  case '\x06':
    pcVar5 = node->base;
    if ((((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0)) &&
        (pcVar1 = pcVar5->sym->def, pcVar1 != (c2_tuple *)0x0)) && (pcVar1->op == 0x15b)) {
      local_4 = propagate_copy_into_use(node,parent);
    }
    break;
  case '\f':
    pcVar5 = (node->u18).children;
    switch(node->op) {
    case 0x15f:
      local_4 = (c2_operand *)simplify_conversion((c2_tuple *)node,parent);
    default:
      goto switchD_10708c16_caseD_3;
    case 0x161:
      if (pcVar5->op == 0x16d) {
        local_4 = tuple_forward_src_and_free((c2_tuple *)node,parent);
        opnd = (c2_fe_symbol *)(local_4->u18).reg;
        while (opnd != (c2_fe_symbol *)0x0) {
          pcVar3 = opnd->next;
          negate_operand((c2_node *)opnd,(c2_tuple *)local_4);
          opnd = pcVar3;
        }
        g_simplify_changed = 1;
      }
      goto switchD_10708c16_caseD_3;
    case 0x16f:
      uVar6 = 0x16d;
      break;
    case 0x171:
      if ((pcVar5->op == 0x16d) &&
         (uVar6 = distribute_constant_over_op((c2_tuple **)&local_4,0x16d,parent), uVar6 != 0))
      goto switchD_10708c16_caseD_3;
    case 0x177:
      if (((pcVar5->op == 0x172) &&
          (uVar6 = distribute_constant_over_op((c2_tuple **)&local_4,0x172,parent), uVar6 != 0)) ||
         ((pcVar5->op == 0x173 &&
          (uVar6 = distribute_constant_over_op((c2_tuple **)&local_4,0x173,parent), uVar6 != 0))))
      goto switchD_10708c16_caseD_3;
      uVar6 = 0x174;
      bVar7 = pcVar5->op == 0x174;
LAB_10708d81:
      if (!bVar7) goto switchD_10708c16_caseD_3;
      break;
    case 0x172:
      uVar6 = distribute_constant_over_op((c2_tuple **)&local_4,0x173,parent);
      if (uVar6 != 0) goto switchD_10708c16_caseD_3;
      uVar6 = 0x174;
      break;
    case 0x173:
      uVar6 = 0x172;
      if (pcVar5->op != 0x172) goto switchD_10708c16_caseD_3;
      bVar7 = (1 << (((pcVar5->u18).children)->next->kind & 0x1f) & 0x380U) == 0;
      goto LAB_10708d81;
    }
    distribute_constant_over_op((c2_tuple **)&local_4,uVar6,parent);
  }
switchD_10708c16_caseD_3:
  if ((1 << (local_4->kind & 0x1f) & 0xffeU) == 0) {
    bVar7 = false;
    pcVar5 = (local_4->u18).children;
    if ((local_4->u18).children != (c2_operand *)0x0) {
      do {
        pcVar2 = pcVar5->next;
        pcVar4 = distribute_and_propagate(pcVar5,(c2_tuple *)local_4);
        if (pcVar4 != pcVar5) {
          bVar7 = true;
        }
        pcVar5 = pcVar2;
      } while (pcVar2 != (c2_operand *)0x0);
      if (bVar7) {
        pcVar5 = distribute_and_propagate(local_4,parent);
        return pcVar5;
      }
    }
  }
  return local_4;
}

