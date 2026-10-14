int __fastcall fe_symbol_size(int cls)

{
  switch(cls) {
  case 1:
  case 0xb:
    return 0x40;
  case 2:
  case 5:
  case 7:
  case 8:
    return 0x46;
  case 3:
    return 0x43;
  case 4:
    return 0x4f;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x693);
  case 9:
    return 0x56;
  case 0xe:
    return 0x7b;
  case 0x10:
    return 0x53;
  }
}

