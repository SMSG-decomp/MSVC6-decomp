int __fastcall op_is_compare_like(uint32_t op)

{
  switch(op) {
  case 0x15f:
  case 0x175:
  case 0x176:
  case 0x177:
  case 0x17d:
  case 0x180:
  case 0x181:
  case 0x182:
  case 0x183:
    return 1;
  default:
    return 0;
  }
}

