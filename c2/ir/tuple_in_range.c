int __fastcall tuple_in_range(c2_node *t,c2_node *from,c2_node *stop)

{
  while( true ) {
    if (from == stop) {
      return 0;
    }
    if (from == t) break;
    from = from->next;
  }
  return 1;
}

