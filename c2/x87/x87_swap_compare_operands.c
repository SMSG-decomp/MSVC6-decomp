void __fastcall x87_swap_compare_operands(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_tuple *pcVar3;
  c2_symbol *pcVar4;
  c2_operand *pcVar5;
  uint32_t uVar6;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  c2_operand *new_op;
  
  pcVar1 = t->src;
  if ((((((pcVar1->u18).reg)->cls == '\x01') && (pcVar1->next->kind == '\x01')) &&
      (pcVar2 = (pcVar1->next->u18).reg, pcVar2->cls == '\x02')) &&
     (((pcVar3 = pcVar1->sym->def, pcVar3->op == 0x60 && (pcVar3->src->kind == '\x01')) &&
      ((pcVar4 = (pcVar3->src->u18).reg, pcVar4->cls == '\x02' &&
       ((pcVar3->next == t && (pcVar3 = t->prev, pcVar7 = pcVar3, (pcVar3->flags & 1) != 0)))))))) {
    do {
      pcVar1 = pcVar7->dst;
      if ((pcVar1 != (c2_operand *)0x0) &&
         ((pcVar1->kind == '\x01' && ((pcVar1->u18).reg == pcVar4)))) break;
      pcVar7 = pcVar7->prev;
    } while ((pcVar7->flags & 1) != 0);
    if ((((((pcVar7->flags & 1) != 0) && (pcVar7->op == 99)) &&
         (pcVar7 = pcVar7->src->sym->def, pcVar7->op == 0x60)) &&
        ((pcVar1 = pcVar7->src, pcVar1->kind == '\x01' && (((pcVar1->u18).reg)->cls == '\x02')))) &&
       (pcVar8 = pcVar3, (pcVar3->flags & 1) != 0)) {
      do {
        pcVar5 = pcVar8->dst;
        if (((pcVar5 != (c2_operand *)0x0) && (pcVar5->kind == '\x01')) &&
           ((pcVar5->u18).reg == pcVar2)) break;
        pcVar8 = pcVar8->prev;
      } while ((pcVar8->flags & 1) != 0);
      if ((((pcVar8->flags & 1) != 0) && (pcVar8->op == 99)) && (pcVar8->src->sym->def->op != 0x60))
      {
        if (pcVar1->sym->cls == '\x03') {
          pcVar7 = pcVar7->next;
          if (pcVar7 == t) {
LAB_1077819a:
            tuple_replace_src(pcVar3,pcVar3->src,pcVar1);
          }
          else {
            do {
              for (pcVar5 = pcVar7->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
                if (((1 << (pcVar5->kind & 0x1f) & 6U) != 0) &&
                   (pcVar5->sym->storage == pcVar1->sym->storage)) {
                  if (pcVar5 != (c2_operand *)0x0) {
                    if (pcVar7 == t) goto LAB_1077819a;
                    goto LAB_1077814c;
                  }
                  break;
                }
              }
              pcVar7 = pcVar7->next;
            } while (pcVar7 != t);
            tuple_replace_src(pcVar3,pcVar3->src,pcVar1);
          }
        }
LAB_1077814c:
        pcVar1 = pcVar3->src;
        new_op = (c2_operand *)node_clone((c2_node *)pcVar1);
        pcVar5 = t->src;
        tuple_replace_src(pcVar3,pcVar1,pcVar5->next);
        tuple_replace_src(t,pcVar5->next,new_op);
        pcVar3 = t->next;
        uVar6 = pcVar3->op;
        while (uVar6 != 0xf) {
          pcVar3 = pcVar3->next;
          uVar6 = pcVar3->op;
        }
        branch_swap_condition(pcVar3);
      }
    }
  }
  return;
}

