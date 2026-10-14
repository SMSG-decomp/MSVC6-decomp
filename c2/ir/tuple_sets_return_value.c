int __fastcall tuple_sets_return_value(c2_tuple *t)

{
  if ((t != (c2_tuple *)0x0) && ((t->kind == '\x0f' || (t->kind == '\x15')))) {
    return 1;
  }
  return 0;
}

