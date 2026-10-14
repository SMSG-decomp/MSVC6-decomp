void __fastcall mark_last_uses_in_range(c2_live_range *lr,c2_tuple *copy)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  c2_bitset *bs;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  c2_block *pcVar8;
  
  pcVar1 = (copy->dst->u18).reg;
  pcVar8 = lr->first_block;
  do {
    uVar7 = lr->id;
    uVar6 = bitset_test(pcVar8->live,uVar7);
    if (uVar6 != 0) {
      bs = pcVar8->live_out;
      uVar6 = bitset_test(bs,uVar7);
      uVar7 = bitset_test(bs,pcVar1->id);
      pcVar4 = pcVar8->head;
      for (pcVar3 = pcVar8->end; pcVar3 != pcVar4; pcVar3 = pcVar3->prev) {
        if ((pcVar3->flags & 1) != 0) {
          for (pcVar2 = pcVar3->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if (pcVar2->kind == '\x01') {
              if ((pcVar2->u18).reg == (c2_symbol *)lr) {
                uVar6 = 0;
              }
              else if ((pcVar2->u18).reg == pcVar1) {
                uVar7 = 0;
              }
            }
          }
          for (pcVar2 = pcVar3->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if ((pcVar2->kind == '\x01') && ((pcVar2->flags11 & 0x10) != 0)) {
              if ((pcVar2->u18).reg == (c2_symbol *)lr) {
                uVar6 = 1;
                uVar5 = uVar7;
              }
              else {
                if ((pcVar2->u18).reg != pcVar1) goto LAB_10725f2a;
                uVar7 = 1;
                uVar5 = uVar6;
              }
              if (uVar5 != 0) {
                pcVar2->flags = pcVar2->flags | 0x80;
              }
            }
LAB_10725f2a:
          }
        }
      }
      if (pcVar8 == lr->last_block) {
        return;
      }
    }
    pcVar8 = pcVar8->next;
  } while( true );
}

