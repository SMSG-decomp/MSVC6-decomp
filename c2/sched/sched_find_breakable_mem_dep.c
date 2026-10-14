c2_operand * __fastcall sched_find_breakable_mem_dep(c2_tuple *a,c2_tuple *b,c2_symbol **reg)

{
  c2_symbol *reg_00;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  pcVar3 = a->dst;
  *reg = (c2_symbol *)0x0;
  do {
    if (pcVar3 == (c2_operand *)0x0) {
LAB_1073ca63:
      reg_00 = *reg;
      if ((reg_00 != (c2_symbol *)0x0) &&
         (pcVar3 = sched_find_mem_operand_using(b,reg_00), pcVar3 != (c2_operand *)0x0)) {
        pcVar1 = b->src;
        for (pcVar2 = pcVar1; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->storage == g_reg_symbols + 0x42)) {
            return (c2_operand *)0x0;
          }
        }
        if ((pcVar1->kind != '\x01') || (((pcVar1->u18).reg)->storage != reg_00)) {
          pcVar1 = pcVar1->next;
          if (pcVar1->kind != '\x01') {
            return pcVar3;
          }
          if (((pcVar1->u18).reg)->storage != reg_00) {
            return pcVar3;
          }
          if (pcVar1 == pcVar3->base) {
            return pcVar3;
          }
          if (pcVar1 == pcVar3->index) {
            return pcVar3;
          }
        }
      }
      return (c2_operand *)0x0;
    }
    if (pcVar3->kind == '\x06') {
      return (c2_operand *)0x0;
    }
    if ((pcVar3->kind == '\x01') && (((pcVar3->u18).reg)->storage != g_reg_symbols + 0x42)) {
      *reg = (c2_symbol *)pcVar3->u18;
      goto LAB_1073ca63;
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

