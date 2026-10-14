int __cdecl conv_rank_based_pointers(int rank,c1_u8 to_flags,c1_u8 from_flags)

{
  if (((to_flags ^ from_flags) & 8) == 0) {
    return rank;
  }
  if (((to_flags & 8) == 0) && ((from_flags & 0x18) != 8)) {
    return rank | 0x10;
  }
  return 0x2000;
}

