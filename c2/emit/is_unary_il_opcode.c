uint32_t __fastcall is_unary_il_opcode(c2_node *t)

{
  switch(t->op) {
  case 0x15a:
  case 0x15b:
  case 0x15c:
  case 0x15d:
  case 0x15e:
  case 0x15f:
  case 0x160:
  case 0x161:
  case 0x162:
  case 0x163:
  case 0x164:
  case 0x16c:
  case 0x186:
  case 0x18d:
  case 0x1ac:
    return 1;
  default:
    return 0;
  }
}

