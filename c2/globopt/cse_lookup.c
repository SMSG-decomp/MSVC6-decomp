c2_cse_expr * __fastcall cse_lookup(uint32_t bucket,uint32_t op,uint16_t type)

{
  int iVar1;
  int iVar2;
  c2_operand **ppcVar3;
  c2_operand *pcVar4;
  c2_cse_expr *pcVar5;
  c2_cse_expr *pcVar6;
  
  iVar1 = op_is_compare_like(op);
  if (iVar1 == 0) {
    for (pcVar5 = g_expr_hash[bucket]; pcVar6 = (c2_cse_expr *)0x0, pcVar5 != (c2_cse_expr *)0x0;
        pcVar5 = pcVar5->next) {
      if ((pcVar5->op == op) && (iVar1 = types_compatible(pcVar5->type,type), iVar1 != 0)) {
        pcVar4 = pcVar5->operands;
        iVar1 = 0;
        if (pcVar4 != (c2_operand *)0x0) {
          ppcVar3 = g_expr_operand_scratch;
          do {
            if ((*ppcVar3 == (c2_operand *)0x0) ||
               (iVar2 = operand_compare(pcVar4,*ppcVar3), iVar2 != 0)) {
              if (pcVar4 != (c2_operand *)0x0) goto LAB_1070d513;
              break;
            }
            pcVar4 = pcVar4->next;
            iVar1 = iVar1 + 1;
            ppcVar3 = ppcVar3 + 1;
          } while (pcVar4 != (c2_operand *)0x0);
        }
        if (g_expr_operand_scratch[iVar1] == (c2_operand *)0x0) {
          return pcVar5;
        }
LAB_1070d513:
        iVar1 = is_commutative_opcode(op);
        if (iVar1 != 0) {
          pcVar4 = pcVar5->operands;
          iVar1 = operand_compare(pcVar4,g_expr_operand_scratch[1]);
          if ((iVar1 == 0) &&
             (iVar1 = operand_compare(pcVar4->next,g_expr_operand_scratch[0]), iVar1 == 0)) {
            return pcVar5;
          }
        }
      }
    }
  }
  else if (op == 0x15f) {
    pcVar6 = g_expr_hash[bucket];
    if (g_opt_qifist == 0) {
      if (pcVar6 != (c2_cse_expr *)0x0) {
        do {
          if ((pcVar6->op == 0x15f) && (iVar1 = types_compatible(pcVar6->type,type), iVar1 != 0)) {
            pcVar4 = pcVar6->operands;
            iVar1 = operand_compare(pcVar4,g_expr_operand_scratch[0]);
            if ((iVar1 == 0) && (pcVar4->type == g_expr_operand_scratch[0]->type)) {
              return pcVar6;
            }
          }
          pcVar6 = pcVar6->next;
          if (pcVar6 == (c2_cse_expr *)0x0) {
            return (c2_cse_expr *)0x0;
          }
        } while( true );
      }
    }
    else if (pcVar6 != (c2_cse_expr *)0x0) {
      do {
        if ((pcVar6->op == 0x15f) && (pcVar6->type == type)) {
          pcVar4 = pcVar6->operands;
          iVar1 = 0;
          if (pcVar4 != (c2_operand *)0x0) {
            ppcVar3 = g_expr_operand_scratch;
            do {
              if ((*ppcVar3 == (c2_operand *)0x0) ||
                 (iVar2 = operand_compare(pcVar4,*ppcVar3), iVar2 != 0)) {
                if (pcVar4 != (c2_operand *)0x0) goto LAB_107800fc;
                break;
              }
              pcVar4 = pcVar4->next;
              iVar1 = iVar1 + 1;
              ppcVar3 = ppcVar3 + 1;
            } while (pcVar4 != (c2_operand *)0x0);
          }
          if (g_expr_operand_scratch[iVar1] == (c2_operand *)0x0) {
            return pcVar6;
          }
        }
LAB_107800fc:
        pcVar6 = pcVar6->next;
        if (pcVar6 == (c2_cse_expr *)0x0) {
          return (c2_cse_expr *)0x0;
        }
      } while( true );
    }
  }
  else {
    pcVar5 = g_expr_hash[bucket];
    pcVar6 = (c2_cse_expr *)0x0;
    if (pcVar5 != (c2_cse_expr *)0x0) {
      do {
        if ((pcVar5->op == op) && (pcVar5->type == type)) {
          pcVar4 = pcVar5->operands;
          iVar1 = 0;
          if (pcVar4 != (c2_operand *)0x0) {
            ppcVar3 = g_expr_operand_scratch;
            do {
              if ((*ppcVar3 == (c2_operand *)0x0) ||
                 (iVar2 = operand_compare(pcVar4,*ppcVar3), iVar2 != 0)) {
                if (pcVar4 != (c2_operand *)0x0) goto LAB_1070d440;
                break;
              }
              pcVar4 = pcVar4->next;
              iVar1 = iVar1 + 1;
              ppcVar3 = ppcVar3 + 1;
            } while (pcVar4 != (c2_operand *)0x0);
          }
          if (g_expr_operand_scratch[iVar1] == (c2_operand *)0x0) {
            return pcVar5;
          }
LAB_1070d440:
          iVar1 = is_commutative_opcode(op);
          if (iVar1 != 0) {
            pcVar4 = pcVar5->operands;
            iVar1 = operand_compare(pcVar4,g_expr_operand_scratch[1]);
            if ((iVar1 == 0) &&
               (iVar1 = operand_compare(pcVar4->next,g_expr_operand_scratch[0]), iVar1 == 0)) {
              return pcVar5;
            }
          }
        }
        pcVar5 = pcVar5->next;
        if (pcVar5 == (c2_cse_expr *)0x0) {
          return (c2_cse_expr *)0x0;
        }
      } while( true );
    }
  }
  return pcVar6;
}

