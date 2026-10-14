int __fastcall range_writes_alias(c2_tuple *first,c2_tuple **end,c2_operand *op)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_operand *b;
  int iVar4;
  c2_operand *pcVar5;
  
  if (op == (c2_operand *)0x0) {
    pcVar1 = *end;
    for (pcVar2 = first; pcVar2 != pcVar1; pcVar2 = pcVar2->next) {
      if (((pcVar2->flags & 1) != 0) && (pcVar5 = pcVar2->dst, pcVar5 != (c2_operand *)0x0)) {
        pcVar3 = first->src;
        b = pcVar3;
        do {
          for (; b != (c2_operand *)0x0; b = b->next) {
            iVar4 = operands_may_alias(pcVar5,b);
            if (iVar4 != 0) {
              return 1;
            }
          }
          pcVar5 = pcVar5->next;
          b = pcVar3;
        } while (pcVar5 != (c2_operand *)0x0);
      }
    }
  }
  else {
    pcVar1 = *end;
    if (first != pcVar1) {
      do {
        if ((first->flags & 1) != 0) {
          for (pcVar5 = first->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            iVar4 = operands_may_alias(pcVar5,op);
            if (iVar4 != 0) {
              return 1;
            }
          }
        }
        first = first->next;
      } while (first != pcVar1);
      return 0;
    }
  }
  return 0;
}

