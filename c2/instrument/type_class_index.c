uint32_t __fastcall type_class_index(uint16_t type)

{
  switch(type >> 0xc) {
  case 0:
    return 0;
  case 1:
    switch(type & 0xfff) {
    case 1:
      return 1;
    case 2:
      return 2;
    case 4:
      return 4;
    case 6:
      return 5;
    case 8:
      return 6;
    }
  case 2:
    switch(type & 0xfff) {
    case 1:
      return 7;
    case 2:
      return 8;
    case 4:
      return 10;
    case 6:
      return 0xb;
    case 8:
      return 0xc;
    }
  case 4:
    if ((type & 0xfff) == 4) {
      return 0xd;
    }
    if ((type & 0xfff) == 8) {
      return 0xe;
    }
    return 0xf;
  case 5:
    switch(type & 0xfff) {
    case 1:
      return 0x13;
    case 2:
      return 0x14;
    default:
      return 0x17;
    case 4:
      return 0x15;
    case 8:
      return 0x16;
    }
  case 6:
    return 0x1c;
  case 7:
    return 0x19;
  case 8:
    return 0x1a;
  case 9:
    return 0x1b;
  case 10:
    return 0x18;
  }
  if ((type & 0xfff) == 4) {
    return 0x10;
  }
  if ((type & 0xfff) != 6) {
    return 0x12;
  }
  return 0x11;
}

