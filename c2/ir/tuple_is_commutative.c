int __fastcall tuple_is_commutative(c2_tuple *t)

{
  switch(t->op) {
  case 0x16d:
  case 0x16f:
  case 0x172:
  case 0x173:
  case 0x174:
  case 0x17e:
  case 0x17f:
    return 1;
  default:
    return 0;
  }
}

