int __cdecl asm_value_fits_bits(char bits,int value)

{
  if (value < 0) {
    value = -value;
  }
  return (uint)(value < 1 << (bits & 0x1fU));
}

