int __fastcall tuple_list_contains(c2_tuple *t,c2_operand *op)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->dst;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      return 0;
    }
    if (pcVar1 == op) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

