void __fastcall clear_tuple_frame_operand_adjustments(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->op == 0x14a) || (pcVar1->op == 0x14e)) {
      pcVar1->rank = 0;
    }
  }
  for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->op == 0x14a) || (pcVar1->op == 0x14e)) {
      pcVar1->rank = 0;
    }
  }
  return;
}

