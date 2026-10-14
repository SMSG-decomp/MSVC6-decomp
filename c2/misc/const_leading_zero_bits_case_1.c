int const_leading_zero_bits_case_1(uint8_t const_lo,int zero_bits)

{
  if (const_lo == '\0') {
    return 8;
  }
  if ((const_lo & 0x80) == 0) {
    do {
      const_lo = const_lo << 1;
      zero_bits = zero_bits + 1;
    } while ((const_lo & 0x80) == 0);
    return zero_bits;
  }
  return zero_bits;
}

