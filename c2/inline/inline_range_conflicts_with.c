int __fastcall inline_range_conflicts_with(c2_operand *op,c2_tuple **first,c2_tuple *end)

{
  c2_tuple *t;
  int iVar1;
  
  t = *first;
  while( true ) {
    if (t == end) {
      return 0;
    }
    if (((t->flags & 1) != 0) && (iVar1 = inline_tuple_conflicts_with(t,op), iVar1 != 0)) break;
    t = t->next;
  }
  return 1;
}

