int __fastcall operand_referenced_between(c2_tuple *first,c2_tuple *last,c2_operand *opnd)

{
  c2_block *pcVar1;
  c2_block *pcVar2;
  int iVar3;
  
  pcVar1 = tuple_get_block(first);
  pcVar2 = tuple_get_block(last);
  while( true ) {
    if (pcVar1 == pcVar2) {
      iVar3 = range_may_alias(first,&last->next,opnd);
      return (uint)(iVar3 != 0);
    }
    iVar3 = range_may_alias(first,&pcVar1->end->next,opnd);
    if (iVar3 != 0) break;
    pcVar1 = pcVar1->succs->to;
    first = pcVar1->head;
  }
  return 1;
}

