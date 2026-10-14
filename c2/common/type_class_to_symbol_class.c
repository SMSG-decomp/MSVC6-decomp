uint32_t __fastcall type_class_to_symbol_class(uint16_t type)

{
  switch(type >> 0xc) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 5;
  case 5:
    return 6;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\getattr.c",0x225);
  }
}

