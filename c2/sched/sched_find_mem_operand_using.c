c2_operand * __fastcall sched_find_mem_operand_using(c2_tuple *t,c2_symbol *reg)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->src;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      pcVar1 = t->dst;
      if (pcVar1 != (c2_operand *)0x0) {
        while (pcVar1->kind != '\x06') {
          pcVar1 = pcVar1->next;
          if (pcVar1 == (c2_operand *)0x0) {
            return (c2_operand *)0x0;
          }
        }
        if (((pcVar1->index == (c2_operand *)0x0) || ((pcVar1->index->u18).reg != reg)) &&
           ((pcVar1->base == (c2_operand *)0x0 || ((pcVar1->base->u18).reg != reg)))) {
LAB_1073cb23:
          pcVar1 = (c2_operand *)0x0;
        }
      }
      return pcVar1;
    }
    if (pcVar1->kind == '\x06') {
      if ((pcVar1->index != (c2_operand *)0x0) && ((pcVar1->index->u18).reg == reg)) {
        return pcVar1;
      }
      if (pcVar1->base != (c2_operand *)0x0) {
        if ((pcVar1->base->u18).reg == reg) {
          return pcVar1;
        }
        return (c2_operand *)0x0;
      }
      goto LAB_1073cb23;
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

