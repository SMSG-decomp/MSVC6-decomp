int __fastcall is_commutative_opcode(uint32_t op)

{
  switch(op) {
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

