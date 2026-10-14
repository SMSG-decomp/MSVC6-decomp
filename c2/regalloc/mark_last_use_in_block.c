void __fastcall mark_last_use_in_block(c2_live_range *lr,c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = t->next;
  if (pcVar2->kind == '\x19') {
    return;
  }
  do {
    if ((pcVar2->flags & 1) != 0) {
      for (pcVar1 = pcVar2->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if (((pcVar1->kind == '\x01') && ((pcVar1->flags11 & 0x10) != 0)) &&
           ((((pcVar1->u18).reg)->storage == ((t->dst->u18).reg)->storage ||
            ((pcVar1->u18).reg == (c2_symbol *)lr)))) {
          pcVar1->flags = pcVar1->flags | 0x80;
          return;
        }
      }
    }
    pcVar2 = pcVar2->next;
    if (pcVar2->kind == '\x19') {
      return;
    }
  } while( true );
}

