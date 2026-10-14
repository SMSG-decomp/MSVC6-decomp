c2_tuple * __fastcall inline_unlink_first_unlinked_def(c2_tuple *first,c2_tuple *end)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *t;
  
  t = first->next;
  if (t == end) {
    return first;
  }
  do {
    pcVar1 = t->next;
    if ((((t->flags & 1) != 0) && (pcVar2 = t->dst, pcVar2 != (c2_operand *)0x0)) &&
       (((1 << (pcVar2->kind & 0x1f) & 6U) == 0 || (pcVar2->sym->def == (c2_tuple *)0x0)))) {
      tuple_unlink(t);
      tuple_insert_after(first,t);
      t->flags12 = '\0';
      hoist_defining_tuples(t,'\0');
      first = t;
    }
    t = pcVar1;
  } while (pcVar1 != end);
  return first;
}

