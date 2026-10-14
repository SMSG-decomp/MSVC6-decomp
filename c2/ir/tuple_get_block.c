c2_block * __fastcall tuple_get_block(c2_tuple *t)

{
  do {
    if (t->kind == '\x19') {
      return (t->u14).arg;
    }
    t = t->prev;
  } while (t != (c2_tuple *)0x0);
  return (c2_block *)0x0;
}

