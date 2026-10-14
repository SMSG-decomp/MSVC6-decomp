int __fastcall tuple_kind_is_control(c2_tuple *t)

{
  switch(t->kind) {
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x11':
  case '\x12':
  case '\x13':
  case '\x14':
    return 1;
  default:
    return 0;
  }
}

