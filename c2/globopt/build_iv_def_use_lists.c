void __fastcall build_iv_def_use_lists(c2_loop *loop)

{
  byte bVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  c2_symbol *pcVar4;
  c2_block *pcVar5;
  c2_tuple *t;
  
  if (g_iv_syms->chunks != (c2_bitset_chunk *)0x0) {
    uVar3 = bitset_iter_next(g_iv_syms);
    while (uVar3 != 0xffffffff) {
      pcVar4 = symbol_by_id(uVar3);
      pcVar4->uses = (c2_list_cell *)0x0;
      pcVar4->defs = (c2_list_cell *)0x0;
      uVar3 = bitset_iter_next((c2_bitset *)0x0);
    }
    pcVar5 = loop->first;
    if (pcVar5 != loop->last->next) {
      do {
        t = pcVar5->head->next;
        if (t != pcVar5->end) {
          do {
            if (((t->flags & 1) != 0) &&
               ((bVar1 = t->flags13, bVar1 == 0 || ((2 < bVar1 && (bVar1 != 0x11)))))) {
              for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                uVar3 = is_induction_variable_operand(pcVar2);
                if (uVar3 != 0) {
                  add_symbol_loop_use(pcVar2->sym,t);
                }
              }
              for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                uVar3 = is_induction_variable_operand(pcVar2);
                if (uVar3 != 0) {
                  add_symbol_loop_def(pcVar2->sym,t);
                }
              }
            }
            t = t->next;
          } while (t != pcVar5->end);
        }
        pcVar5 = pcVar5->next;
      } while (pcVar5 != loop->last->next);
    }
  }
  return;
}

