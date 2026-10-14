uint32_t __fastcall sink_common_tails_of_label(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *kept_jmp;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  int iVar4;
  
  pcVar3 = tuple_prev_real(t);
  if ((pcVar3 != (c2_tuple *)0x0) &&
     ((((pcVar3->kind == '\x11' && ((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0)) &&
       (pcVar3->op != 0x18b)) || (pcVar3->kind == '\x0f')))) {
    for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
      pcVar3 = (c2_tuple *)pcVar1->rank;
      if (((pcVar3->kind == '\x11') && ((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0)) &&
         (pcVar3->op != 0x18b)) {
        for (pcVar2 = pcVar1->next; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          kept_jmp = (c2_tuple *)pcVar2->rank;
          if (((kept_jmp->kind == '\x11') && ((kept_jmp->u20).cond_cells == (c2_cond_cell *)0x0)) &&
             ((kept_jmp->op != 0x18b && (iVar4 = sink_common_tail_pair(pcVar3,kept_jmp), iVar4 != 0)
              ))) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

