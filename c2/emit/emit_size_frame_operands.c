void __fastcall emit_size_frame_operands(c2_function *fn,void *rec)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  
  if ((g_opt_favor_speed != 0) && ((*(byte *)((int)rec + 0x34) & 0x10) != 0)) {
    for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
      if ((pcVar1->flags & 1) != 0) {
        for (pcVar2 = pcVar1->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if ((pcVar2->op == 0x14a) || (pcVar2->op == 0x14e)) {
            emit_set_frame_operand_size(pcVar2);
          }
        }
        for (pcVar2 = pcVar1->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if ((pcVar2->op == 0x14a) || (pcVar2->op == 0x14e)) {
            emit_set_frame_operand_size(pcVar2);
          }
        }
      }
    }
  }
  return;
}

