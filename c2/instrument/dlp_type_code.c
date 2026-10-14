uint32_t __fastcall dlp_type_code(uint16_t type)

{
  uint32_t uVar1;
  
  uVar1 = type_class_index(type);
  switch(uVar1) {
  case 1:
    return 0x10;
  case 2:
    return 0x72;
  default:
    return 0;
  case 4:
    return 0x74;
  case 6:
    return 0x76;
  case 7:
    return 0x20;
  case 8:
    return 0x73;
  case 10:
  case 0x10:
    return 0x75;
  case 0xc:
  case 0x12:
    return 0x77;
  case 0xd:
    return 0x40;
  case 0xe:
    return 0x41;
  case 0xf:
    return 0x42;
  }
}

