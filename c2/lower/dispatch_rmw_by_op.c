uint64_t __fastcall dispatch_rmw_by_op(c2_tuple *t)

{
  switch(t->op) {
  default:
    return 0;
  case 0x16f:
    return 1;
  case 0x172:
    return 0xffffffffffffffff;
  }
}

