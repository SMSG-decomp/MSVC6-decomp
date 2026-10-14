c2_block * __fastcall tuple_get_block_nonnull(c2_tuple *t)

{
  for (; (t->kind != '\x19' || ((t->u14).arg == (void *)0x0)); t = t->prev) {
  }
  return (t->u14).arg;
}

