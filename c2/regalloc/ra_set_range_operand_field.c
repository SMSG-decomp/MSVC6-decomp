void __fastcall ra_set_range_operand_field(c2_live_range *lr,uint8_t value)

{
  uint32_t uVar1;
  c2_operand *pcVar2;
  int iVar3;
  c2_block *pcVar4;
  c2_tuple *pcVar5;
  
  pcVar4 = lr->first_block;
  do {
    uVar1 = bitset_test(pcVar4->live,lr->id);
    if (uVar1 != 0) {
      pcVar5 = pcVar4->head;
      if (pcVar5 != pcVar4->end) {
        do {
          if ((pcVar5->flags & 1) != 0) {
            if (pcVar5->op == 0x163) {
              if ((pcVar5->dst->u18).reg == (c2_symbol *)lr) {
                pcVar2 = pcVar5->src;
LAB_1076e4ff:
                pcVar2->flags11 = (pcVar2->flags11 ^ value) & 7 ^ pcVar2->flags11;
              }
            }
            else if (pcVar5->op == 0x164) {
              if ((pcVar5->src->u18).reg == (c2_symbol *)lr) {
                pcVar2 = pcVar5->dst;
                goto LAB_1076e4ff;
              }
            }
            else {
              iVar3 = 0;
              do {
                if (iVar3 == 0) {
                  pcVar2 = pcVar5->dst;
                }
                else {
                  pcVar2 = pcVar5->src;
                }
                for (; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                  if ((pcVar2->kind == '\x01') && ((pcVar2->u18).reg == (c2_symbol *)lr)) {
                    pcVar2->flags11 = pcVar2->flags11 & 0xf8;
                  }
                }
                iVar3 = iVar3 + 1;
              } while (iVar3 < 2);
            }
          }
          pcVar5 = pcVar5->next;
        } while (pcVar5 != pcVar4->end);
      }
      if (pcVar4 == lr->last_block) {
        return;
      }
    }
    pcVar4 = pcVar4->next;
  } while( true );
}

