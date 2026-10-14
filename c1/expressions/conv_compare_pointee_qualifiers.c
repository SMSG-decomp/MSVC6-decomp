int __cdecl conv_compare_pointee_qualifiers(int mode,int rank,ushort to_flags,ushort from_flags)

{
  if (to_flags == from_flags) {
    return rank;
  }
  if ((to_flags & 0x20) == 0) {
    if ((from_flags & 0x20) != 0) {
      return 0x2005;
    }
  }
  else if ((from_flags & 0x20) == 0) {
    rank = rank | 8;
  }
  if ((to_flags & 0x40) == 0) {
    if ((from_flags & 0x40) != 0) {
      return 0x2006;
    }
  }
  else if ((from_flags & 0x40) == 0) {
    rank = rank | 8;
  }
  return rank;
}

