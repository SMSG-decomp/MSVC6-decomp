c1_u8 __cdecl type_check_bitfield_width(c1_symbol *member,uint width_lo,int width_hi)

{
  if (((width_hi < 0) || (0 < width_hi)) || ((-1 < width_hi && (0xff < width_lo)))) {
    diag_error(0x22,member);
    width_lo = 1;
  }
  return (c1_u8)width_lo;
}

