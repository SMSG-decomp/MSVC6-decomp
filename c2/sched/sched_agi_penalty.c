int __fastcall sched_agi_penalty(c2_sched_edge *edge,c2_symbol *sym2)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  
  pcVar1 = edge->to->tuple;
  pcVar2 = pcVar1->src;
  do {
    if (pcVar2 == (c2_operand *)0x0) {
      pcVar2 = pcVar1->dst;
      while( true ) {
        if (pcVar2 == (c2_operand *)0x0) {
          pcVar3 = edge->from->tuple;
          if (((((sym2 == g_reg_symbols + 5) && (uVar5 = pcVar3->op, uVar5 != 0xd)) &&
               (uVar5 != 0xc)) && ((uVar5 != 0xba && (uVar5 != 0xb9)))) &&
             (((uVar5 = pcVar1->op, uVar5 == 0xd || ((uVar5 == 0xc || (uVar5 == 0xba)))) ||
              (uVar5 == 0xb9)))) {
            if ((((byte)g_cur_func_sym->attrs & 0x1c) == 4) && (pcVar3->kind == '\x0e')) {
              return 2;
            }
            return 1;
          }
          return 0;
        }
        if (pcVar2->kind == '\x06') break;
        pcVar2 = pcVar2->next;
      }
      pcVar4 = pcVar2->index;
joined_r0x1073b3b9:
      if ((pcVar4 != (c2_operand *)0x0) && ((pcVar4->u18).reg == sym2)) {
        return 1;
      }
      if (pcVar2->base == (c2_operand *)0x0) {
        return 0;
      }
      if ((pcVar2->base->u18).reg != sym2) {
        return 0;
      }
      return 1;
    }
    if ((pcVar2->kind == '\x06') || (pcVar2->kind == '\x05')) {
      pcVar4 = pcVar2->index;
      goto joined_r0x1073b3b9;
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

