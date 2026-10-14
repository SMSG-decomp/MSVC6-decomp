int __fastcall inline_range_may_write(c2_operand *op,c2_tuple **first,c2_tuple *end)

{
  c2_tuple *t;
  int iVar1;
  
  t = *first;
  while( true ) {
    if (t == end) {
      return 0;
    }
    if ((((t->flags & 1) != 0) && (t->op != 0x15a)) &&
       (iVar1 = inline_tuple_may_write(t,op), iVar1 != 0)) break;
    t = t->next;
  }
  return 1;
}

