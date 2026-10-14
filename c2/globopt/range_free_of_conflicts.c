int __fastcall range_free_of_conflicts(c2_tuple *first,c2_tuple *last,c2_tuple *tree)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  c2_operand *pcVar5;
  
  pcVar1 = last->next;
  do {
    if (first == pcVar1) {
      return 1;
    }
    if ((first->flags & 1) != 0) {
      pcVar5 = first->dst;
      if (pcVar5 != (c2_operand *)0x0) {
        pcVar2 = tree->src;
        pcVar3 = pcVar2;
        do {
          for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            iVar4 = operands_may_alias(pcVar5,pcVar3);
            if (iVar4 != 0) {
              return 0;
            }
          }
          for (pcVar3 = tree->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            iVar4 = operands_may_alias(pcVar5,pcVar3);
            if (iVar4 != 0) {
              return 0;
            }
          }
          pcVar5 = pcVar5->next;
          pcVar3 = pcVar2;
        } while (pcVar5 != (c2_operand *)0x0);
      }
      pcVar5 = first->src;
      if (pcVar5 != (c2_operand *)0x0) {
        pcVar2 = tree->dst;
        pcVar3 = pcVar2;
        do {
          for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            iVar4 = operands_may_alias(pcVar5,pcVar3);
            if (iVar4 != 0) {
              return 0;
            }
          }
          pcVar5 = pcVar5->next;
          pcVar3 = pcVar2;
        } while (pcVar5 != (c2_operand *)0x0);
      }
    }
    first = first->next;
  } while( true );
}

