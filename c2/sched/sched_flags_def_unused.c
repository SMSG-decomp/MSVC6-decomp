int __fastcall sched_flags_def_unused(c2_operand *op,c2_tuple **from,c2_tuple **end)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  if ((((op->u18).reg == g_reg_symbols + 0x42) && (op->sym == g_reg_symbols + 0x42)) &&
     (pcVar2 = *from, pcVar2 != (c2_tuple *)0x0)) {
    do {
      if (pcVar2 == *end) {
        return 0;
      }
      if ((pcVar2->flags & 1) == 0) {
        return 0;
      }
      if (pcVar2->kind == '\x11') {
        return 0;
      }
      for (pcVar1 = pcVar2->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if ((pcVar1->kind == '\x01') && (((pcVar1->u18).reg)->storage == g_reg_symbols + 0x42)) {
          return 0;
        }
      }
      for (pcVar1 = pcVar2->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if ((pcVar1->kind == '\x01') && (((pcVar1->u18).reg)->storage == g_reg_symbols + 0x42)) {
          return 1;
        }
      }
      pcVar2 = pcVar2->next;
    } while (pcVar2 != (c2_tuple *)0x0);
  }
  return 0;
}

