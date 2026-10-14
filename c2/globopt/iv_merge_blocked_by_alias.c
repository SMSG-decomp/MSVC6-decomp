int __fastcall iv_merge_blocked_by_alias(c2_operand *op,c2_tuple *a,c2_tuple *b)

{
  c2_tuple *first;
  uint32_t uVar1;
  c2_tuple *pcVar2;
  int iVar3;
  
  uVar1 = block_range_dominated(a,b);
  pcVar2 = a;
  if (uVar1 != 0) {
    pcVar2 = b;
    b = a;
  }
  first = b->next->next;
  if (first != pcVar2) {
    iVar3 = range_may_alias(first,&pcVar2->prev->next,op);
    return (uint)(iVar3 != 0);
  }
  return 0;
}

