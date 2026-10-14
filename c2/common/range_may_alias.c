int __fastcall range_may_alias(c2_tuple *first,c2_tuple **end,c2_operand *op)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  int iVar3;
  
  pcVar1 = *end;
  do {
    if (first == pcVar1) {
      return 0;
    }
    if ((first->flags & 1) != 0) {
      for (pcVar2 = first->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        iVar3 = operands_may_alias(pcVar2,op);
        if (iVar3 != 0) {
          return 1;
        }
      }
      for (pcVar2 = first->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        iVar3 = operands_may_alias(pcVar2,op);
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
    first = first->next;
  } while( true );
}

