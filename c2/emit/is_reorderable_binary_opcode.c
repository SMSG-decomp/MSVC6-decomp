uint32_t __fastcall is_reorderable_binary_opcode(c2_node *t)

{
  switch(t->op) {
  case 0x16d:
  case 0x16e:
  case 0x16f:
  case 0x171:
  case 0x172:
  case 0x173:
  case 0x174:
  case 0x175:
  case 0x176:
  case 0x177:
  case 0x178:
  case 0x17d:
  case 0x17e:
  case 0x17f:
  case 0x180:
  case 0x181:
  case 0x182:
  case 0x183:
    return 1;
  default:
    return 0;
  }
}

