int __fastcall canonicalize_mark_materialize_pred(c2_tuple *t)

{
  if (t->flags13 != '\x11') {
    t->flags13 = '\x11';
    return 0;
  }
  return 1;
}

