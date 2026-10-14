uint8_t __fastcall coff_comdat_selection_code(uint8_t comdat_kind)

{
  switch(comdat_kind) {
  case '\x01':
    return '\x02';
  case '\x02':
    return '\x01';
  case '\x03':
    return '\x03';
  case '\x04':
    return '\x04';
  case '\x05':
    return '\x05';
  case '\x06':
    return '\x06';
  case '\a':
    return '\a';
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x88b);
  }
}

