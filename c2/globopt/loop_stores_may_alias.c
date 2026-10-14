int __fastcall
loop_stores_may_alias(c2_operand *dst,c2_operand *src,c2_tuple *store,c2_loop *loop,int *partial)

{
  c2_cse_expr *pcVar1;
  c2_operand *pcVar2;
  int on;
  int iVar3;
  c2_block *pcVar4;
  c2_tuple *pcVar5;
  int iVar6;
  c2_block *local_c;
  
  iVar6 = 0;
  on = set_alias_field_overlap_test(0);
  if (src == (c2_operand *)0x0) {
    pcVar4 = loop->first;
    if (pcVar4 != loop->last->next) {
      do {
        pcVar5 = pcVar4->head->next;
        if (pcVar5 != pcVar4->end) {
          do {
            if ((pcVar5->flags & 1) != 0) {
              for (pcVar2 = pcVar5->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                iVar3 = operands_may_alias(dst,pcVar2);
                if (iVar3 != 0) goto code_r0x10761b4d;
              }
              if (pcVar5 != store) {
                for (pcVar2 = pcVar5->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                  iVar3 = operands_may_alias(dst,pcVar2);
                  if (iVar3 != 0) goto code_r0x10761b4d;
                }
              }
            }
            pcVar5 = pcVar5->next;
          } while (pcVar5 != pcVar4->end);
        }
        pcVar4 = pcVar4->next;
      } while (pcVar4 != loop->last->next);
    }
  }
  else {
    local_c = loop->first;
    if (local_c != loop->last->next) {
      do {
        pcVar5 = local_c->head->next;
        if (pcVar5 != local_c->end) {
          do {
            if ((pcVar5->flags & 1) != 0) {
              for (pcVar2 = pcVar5->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                if ((src == pcVar2) && (pcVar2->kind == '\x06')) {
                  iVar3 = operands_may_alias(dst,pcVar2);
                  if (iVar3 != 0) {
                    *partial = 1;
                  }
                  set_alias_field_overlap_test(on);
                  iVar3 = operands_may_alias(dst,pcVar2);
                  if (iVar3 != 0) goto code_r0x10761b4d;
                  set_alias_field_overlap_test(0);
                }
                else {
                  iVar3 = operands_may_alias(dst,pcVar2);
                  if (iVar3 != 0) goto code_r0x10761b4d;
                }
                if ((((pcVar5 != store) && ((1 << (pcVar2->kind & 0x1f) & 6U) != 0)) &&
                    (pcVar1 = (pcVar2->sym->u18).expr, pcVar1 != (c2_cse_expr *)0x0)) &&
                   ((pcVar1->op == 0x15d &&
                    (iVar3 = operands_may_alias(pcVar2,store->src), iVar3 != 0)))) {
                  iVar6 = loop_stores_may_alias_part(iVar6,on);
                  return iVar6;
                }
              }
              if (pcVar5 != store) {
                for (pcVar2 = pcVar5->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                  iVar3 = operands_may_alias(src,pcVar2);
                  if ((iVar3 != 0) || (iVar3 = operands_may_alias(dst,pcVar2), iVar3 != 0))
                  goto code_r0x10761b4d;
                }
              }
            }
            pcVar5 = pcVar5->next;
          } while (pcVar5 != local_c->end);
        }
        local_c = local_c->next;
      } while (local_c != loop->last->next);
    }
  }
LAB_107619ad:
  set_alias_field_overlap_test(on);
  return iVar6;
code_r0x10761b4d:
  iVar6 = 1;
  goto LAB_107619ad;
}

