int __fastcall range_dst_may_alias(c2_tuple *first,c2_tuple **end,c2_operand *op)

{
  c2_tuple *pcVar1;
  c2_operand *a;
  int iVar2;
  
  pcVar1 = *end;
  do {
    if (first == pcVar1) {
      return 0;
    }
    if ((first->flags & 1) != 0) {
      for (a = first->dst; a != (c2_operand *)0x0; a = a->next) {
        iVar2 = operands_may_alias(a,op);
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
    first = first->next;
  } while( true );
}

