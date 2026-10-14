int __fastcall sizeopt_def_known_bits(c2_tuple *t)

{
  switch(t->op) {
  case 0x15b:
  case 0x160:
  case 0x161:
  case 0x16d:
  case 0x16e:
  case 0x16f:
  case 0x172:
  case 0x173:
  case 0x174:
    return (uint)(t->dst->sym->u30).globopt.killed;
  default:
    return 0;
  case 0x171:
  case 0x175:
  case 0x177:
    return 0;
  }
}

