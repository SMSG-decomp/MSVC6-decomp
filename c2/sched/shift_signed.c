uint32_t __fastcall shift_signed(uint32_t x,int w)

{
  if (w < 0) {
    return x >> (-(byte)w & 0x1f);
  }
  return x << ((byte)w & 0x1f);
}

