uint32_t __fastcall coff_align_characteristic(uint32_t align)

{
  switch(align) {
  case 1:
    return 0x100000;
  case 2:
    return 0x200000;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x8c7);
  case 4:
    return 0x300000;
  case 8:
    return 0x400000;
  case 0x10:
    return 0x500000;
  case 0x20:
    return 0x600000;
  case 0x40:
    return 0x700000;
  }
}

