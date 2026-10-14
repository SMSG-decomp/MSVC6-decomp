int __cdecl debug_cv_calling_convention(ushort type_flags)

{
  switch(type_flags & 7) {
  case 0:
  case 1:
    return 0;
  case 2:
    return 2;
  case 3:
    return 4;
  case 4:
  case 5:
    return 7;
  case 6:
    return 0xb;
  default:
    return 0x12;
  }
}

